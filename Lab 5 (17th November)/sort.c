#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node;

node *create_node(int val) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

node *sort_list(node *head) {
    int swapped;
    node *ptr1;
    node *lptr = NULL;
    if (head == NULL)
        return head;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->val > ptr1->next->val) {
                int temp = ptr1->val;
                ptr1->val = ptr1->next->val;
                ptr1->next->val = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    return head;
}

int main() {
    node *head = create_node(4);
    head->next = create_node(1);
    head->next->next = create_node(5);
    head->next->next->next = create_node(2);
    head->next->next->next->next = create_node(3);
    printf("Original list: ");
    print_list(head);
    head = sort_list(head);
    printf("Sorted list: ");
    print_list(head);
    return 0;
}