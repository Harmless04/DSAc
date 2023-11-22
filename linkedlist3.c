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

void insertBefore(struct Node** head, int targetData, int newData) {
    struct Node* newNode = createNode(newData);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if ((*head)->data == targetData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data != targetData) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("invalid.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
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
    int n, data, targetData;

    printf("Enter the number of elements ");
    scanf("%d", &n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }

    printf("Linked List ");
    printList(head);

    printf("Enter the data before which you want to insert a new node ");
    scanf("%d", &targetData);

    int newData;
    printf("Enter the data for the new node ");
    scanf("%d", &newData);

    insertBefore(&head, targetData, newData);

    printf("Updated Linked List ");
    printList(head);

    return 0;
}
