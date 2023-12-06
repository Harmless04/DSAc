#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("invalid");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void addAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("invalid.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, insertData;

    printf("Enter the number of elements ");
    scanf("%d", &n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        addAtEnd(&head, data);
    }

    printf("Linked List ");
    printList(head);

    printf("Enter the data after which you want to insert a new node ");
    scanf("%d", &insertData);


    struct Node* current = head;
    while (current != NULL && current->data != insertData) {
        current = current->next;
    }

    int newData;
    printf("Enter the data for the new node ");
    scanf("%d", &newData);

    insertAfter(current, newData);

    printf("New Linked List ");
    printList(head);

    return 0;
}
