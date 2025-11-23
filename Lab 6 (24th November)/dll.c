#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { 
        printf("Memory allocation failed\n");
        exit(1); 
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) 
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void displayList(Node* head) {
    Node* temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("List contents: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* findNode(Node* head, int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void insertLeft(Node** head, int target, int data) {
    Node* targetNode = findNode(*head, target);
    if (!targetNode) {
        printf("Node with value %d not found.\n", target);
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = targetNode;
    newNode->prev = targetNode->prev;
    if (targetNode->prev)
        targetNode->prev->next = newNode;
    else
        *head = newNode;
    targetNode->prev = newNode;
}

void deleteNode(Node** head, int value) {
    Node* targetNode = findNode(*head, value);
    if (!targetNode) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    if (targetNode->prev)
        targetNode->prev->next = targetNode->next;
    else
        *head = targetNode->next;
    if (targetNode->next)
        targetNode->next->prev = targetNode->prev;

    free(targetNode);
    printf("Deleted node with value %d.\n", value);
}

int main() {
    Node* head = NULL;
    int choice, value, target;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert node at end (Create list)\n");
        printf("2. Insert node to the left of a node\n");
        printf("3. Delete node by value\n");
        printf("4. Display list\n");
        printf("Enter your choice (any other key to exit): ");
        if (scanf("%d", &choice) != 1)
            break;
        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Enter target node value to insert left of: ");
                scanf("%d", &target);
                printf("Enter new node value: ");
                scanf("%d", &value);
                insertLeft(&head, target, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                displayList(head);
                break;
            default:
                printf("Exiting.\n");
                exit(0);
        }
    }
    return 0;
}
