#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
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
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteSmallest(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    int smallest = current->data;

    while (current->next != NULL) {
        if (current->next->data < smallest) {
            smallest = current->next->data;
            prev = current;
        }
        current = current->next;
    }


    if (prev == NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        struct Node* temp = prev->next;
        prev->next = prev->next->next;
        free(temp);
    }
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
    struct Node* head = NULL;
    int n, data;


    printf("Enter the number of elements: ");
    scanf("%d", &n);


    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        addAtEnd(&head, data);
    }


    printf("Linked List: ");
    displayList(head);


    deleteSmallest(&head);

    // Display the linked list after deletion
    printf("Linked List after deleting the smallest element: ");
    displayList(head);

    // Free the memory occupied by the linked list
    freeList(head);

    return 0;
}
