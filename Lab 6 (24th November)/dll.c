#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

node* createnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    if (!newnode) { 
        printf("Memory allocation failed\n");
        exit(1); 
    }
    newnode->data = data;
    newnode->prev = newnode->next = NULL;
    return newnode;
}

void insertEnd(node** head, int data) {
    node* newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) 
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void displayList(node* head) {
    node* temp = head;
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

node* findnode(node* head, int value) {
    node* temp = head;
    while (temp) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void insertLeft(node** head, int target, int data) {
    node* targetnode = findnode(*head, target);
    if (!targetnode) {
        printf("node with value %d not found.\n", target);
        return;
    }
    node* newnode = createnode(data);
    newnode->next = targetnode;
    newnode->prev = targetnode->prev;
    if (targetnode->prev)
        targetnode->prev->next = newnode;
    else
        *head = newnode;
    targetnode->prev = newnode;
}

void deletenode(node** head, int value) {
    node* targetnode = findnode(*head, value);
    if (!targetnode) {
        printf("node with value %d not found.\n", value);
        return;
    }
    if (targetnode->prev)
        targetnode->prev->next = targetnode->next;
    else
        *head = targetnode->next;
    if (targetnode->next)
        targetnode->next->prev = targetnode->prev;

    free(targetnode);
    printf("Deleted node with value %d.\n", value);
}

int main() {
    node* head = NULL;
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
                deletenode(&head, value);
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
