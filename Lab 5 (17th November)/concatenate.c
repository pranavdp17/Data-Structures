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

node *concatenate_lists(node *head1, node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    node *current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
    return head1;
}

int main() {
    node *head1 = create_node(1);
    head1->next = create_node(2);
    head1->next->next = create_node(3);
    node *head2 = create_node(4);
    head2->next = create_node(5);
    head2->next->next = create_node(6);
    printf("List 1 before concatenation: ");
    print_list(head1);
    printf("List 2 before concatenation: ");
    print_list(head2);
    head1 = concatenate_lists(head1, head2);
    printf("List after concatenation: ");
    print_list(head1);
    return 0;
}