#include <stdio.h>
#define MAX_SIZE 5
int stack[MAX_SIZE];
int top=-1;

void push()
{
    if(top==MAX_SIZE-1)
    {
        printf("Overflow\n");
        return;
    }
    int a;
    printf("Enter element  to insert\n");
    scanf("%d",&a);
    top++;
    stack[top]=a;
    printf("Element pushed\n");
}

void pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
        return;
    }
    top--;
    printf("Element  popped\n");
}

void display()
{
    if(top==-1)
    {
        printf("Undeflow\n");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}

void main()
{
    int arr[MAX_SIZE];
    int s = 0;
    while (s!=4)
    {
        printf("Enter 1 for pushing element to stack\nEnter 2 for popping an element  from an array\nEnter 3 for displaying the stack\nEnter 4 for exiting\n");
        scanf("%d", &s);
        switch (s)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exiting!!!!!");
                break;
            }
            default:
            {
                printf("Enter a valid Input");
                break;
            }
        }
    }
}
