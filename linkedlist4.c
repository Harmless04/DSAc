#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

   
    if (temp == NULL) {
        printf("Key not found in the linked list.\n");
        return;
    }

 
    prev->next = temp->next;
    free(temp);
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    int n, data;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Original linked list: ");
    printList(head);

    int key;
    printf("Enter the key to be deleted: ");
    scanf("%d", &key);

    
    deleteNode(&head, key);

    printf("Updated linked list: ");
    printList(head);

    freeList(head);

    return 0;
}
