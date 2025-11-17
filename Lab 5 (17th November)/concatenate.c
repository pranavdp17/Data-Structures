#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

node_t *create_node(int val) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

node_t *concatenate_lists(node_t *head1, node_t *head2) {
    if (head1 == NULL) {
        return head2;
    }

    node_t *current = head1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = head2;
    return head1;
}

void free_list(node_t *head) {
    node_t *current = head;
    node_t *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    node_t *head1 = create_node(1);
    head1->next = create_node(2);
    head1->next->next = create_node(3);

    node_t *head2 = create_node(4);
    head2->next = create_node(5);
    head2->next->next = create_node(6);

    printf("List 1 before concatenation: ");
    print_list(head1);
    printf("List 2 before concatenation: ");
    print_list(head2);

    head1 = concatenate_lists(head1, head2);

    printf("List after concatenation: ");
    print_list(head1);

    free_list(head1);

    return 0;
}