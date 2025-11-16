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

node_t *sort_list(node_t *head) {
    int swapped;
    node_t *ptr1;
    node_t *lptr = NULL;

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
    node_t *head = create_node(4);
    head->next = create_node(1);
    head->next->next = create_node(5);
    head->next->next->next = create_node(2);
    head->next->next->next->next = create_node(3);

    printf("Original list: ");
    print_list(head);

    head = sort_list(head);

    printf("Sorted list: ");
    print_list(head);

    free_list(head);

    return 0;
}