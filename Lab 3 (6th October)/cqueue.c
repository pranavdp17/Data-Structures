#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void insert(int x)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = x;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Empty\n");
    }
    else
    {
        printf("%d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    int s = 0, x;
    while (s != 4)
    {
        printf("Enter 1 for inserting element to queue\nEnter 2 for deleting an element from queue\nEnter 3 for displaying the queue\nEnter 4 for exiting\n");
        scanf("%d", &s);
        switch (s)
        {
            case 1:
                printf("Enter element to be inserted\n");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting!!!!!\n");
                break;
            default:
                printf("Enter a valid Input\n");
                break;
        }
    }
}
