#include <stdio.h>
#include <stdlib.h>
#define size 5

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *newnode, *temp;
    int i, val;
    printf("Enter values of the initial linked list :\n");
    for(i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &val);
        newnode->data = val;
        newnode->next = NULL;
        if(head == NULL) head = newnode;
        else {
            temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp->next = newnode;
        }
    }
}

void insert_begin(int val) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void insert_end(int val) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL) head = newnode;
    else {
        struct node *temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newnode;
    }
}

void insert_pos(int val, int pos) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    if(pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    struct node *temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;
    if(temp == NULL) return;
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin() {
    if (head == NULL) return;
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void delete_node(int val) {
    if (head == NULL) return;
    if (head->data == val) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL && temp->next->data != val) temp = temp->next;
    if (temp->next == NULL) return;
    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void delete_after(int val) {
    struct node *temp = head;
    while (temp != NULL && temp->data != val) temp = temp->next;
    if (temp == NULL || temp->next == NULL) return;
    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, value, pos;
    create(size);
    while(1){
        printf("\nEnter choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete node by value\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_begin(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_end(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insert_pos(value, pos);
                break;
            case 7:
                display();
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete_node(value);
                break;
            case 8:
                printf("Exiting!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}