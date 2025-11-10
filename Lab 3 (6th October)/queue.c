#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

int isfull()
{
    if (rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int isempty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    return 0;
}

void insert(int x)
{
    if (isfull())
    {
        printf("Queue is Full\n");
        return;
    }
    if (isempty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = x;
}

void delete()
{
    if (isempty())
    {
        printf("Cant Delete\n");
        return;
    }
    int x = queue[front];
    printf("%d\n", x);
    front++;
}

void display()
{
    if (isempty())
    {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
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
