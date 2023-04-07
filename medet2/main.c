#include <stdio.h>
#include <stdlib.h>

// D���m yap�s�
struct Node {
    int data;
    struct Node* next;
};

// Palindrom kontrol fonksiyonu
int isPalindrome(int num) {
    int reversed = 0, remainder, original;
    original = num;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    if (original == reversed) {
        return 1;
    } else {
        return 0;
    }
}

// Palindrom say�ya ba�l� liste olu�turma fonksiyonu
void createPalindromeList(struct Node** head_ref, int start, int end) {
    struct Node* current = *head_ref;
    for (int i = start; i <= end; i++) {
        if (isPalindrome(i)) {
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = i;
            new_node->next = NULL;

            if (*head_ref == NULL) {
                *head_ref = new_node;
                current = new_node;
            } else {
                current->next = new_node;
                current = new_node;
            }
        }
    }
}

// Ba�l� listenin palindrom olup olmad���n� kontrol eden fonksiyon
int isListPalindrome(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if (!isPalindrome(current->data)) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

// Test fonksiyonu
void test() {
    struct Node* head = NULL;
    createPalindromeList(&head, 100, 150);

    printf("Ba�l� Liste: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    if (isListPalindrome(head)) {
        printf("Ba�l� liste palindromdur.\n");
    } else {
        printf("Ba�l� liste palindrom de�ildir.\n");
    }
}

int main() {
    test();
    return 0;
}
