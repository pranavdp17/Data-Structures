#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* createnode(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(node** top, int data) {
    node* temp = createnode(data);
    temp->next = *top;
    *top = temp;
    printf("Pushed %d to stack\n", data);
}

int pop(node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int peekStack(node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void displayStack(node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(node** front, node** rear, int data) {
    node* temp = createnode(data);
    if (*rear == NULL) {
        *front = *rear = temp;
        printf("Enqueued %d to queue\n", data);
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
    printf("Enqueued %d to queue\n", data);
}

int dequeue(node** front, node** rear) {
    if (*front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    node* temp = *front;
    int dequeued = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return dequeued;
}

int peekQueue(node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

void displayQueue(node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* stackTop = NULL;
    node* queueFront = NULL;
    node* queueRear = NULL;
    
    printf(" Stack Operations \n");
    push(&stackTop, 1);
    push(&stackTop, 2);
    push(&stackTop, 3);
    push(&stackTop, 4);
    displayStack(stackTop);
    printf("Top element: %d\n", peekStack(stackTop));
    printf("Popped: %d\n", pop(&stackTop));
    printf("Popped: %d\n", pop(&stackTop));
    displayStack(stackTop);
    
    printf("\n Queue Operations \n");
    enqueue(&queueFront, &queueRear, 5);
    enqueue(&queueFront, &queueRear, 1);
    enqueue(&queueFront, &queueRear, 2);
    enqueue(&queueFront, &queueRear, 3);
    displayQueue(queueFront);
    printf("Front element: %d\n", peekQueue(queueFront));
    printf("Dequeued: %d\n", dequeue(&queueFront, &queueRear));
    printf("Dequeued: %d\n", dequeue(&queueFront, &queueRear));
    displayQueue(queueFront);
    
    return 0;
}