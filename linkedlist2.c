#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);

    
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

   
    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

  
    lastNode->next = newNode;
}


void insertAtPosition(struct Node** headRef, int data, int position) {
    struct Node* newNode = createNode(data);

  
    if (position == 0) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

  
    struct Node* current = *headRef;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    
    if (current == NULL) {
        printf("Invalid position for insertion.\n");
        return;
    }

    
    newNode->next = current->next;
    current->next = newNode;
}


void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;

    int n;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int element;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        append(&head, element);
    }

  
    printf("Original Linked List: ");
    display(head);

 
    int position, element;
    printf("Enter the position for insertion: ");
    scanf("%d", &position);
    printf("Enter the element to insert: ");
    scanf("%d", &element);

  
    insertAtPosition(&head, element, position);

 
    printf("Linked List after insertion: ");
    display(head);

    return 0;
}
