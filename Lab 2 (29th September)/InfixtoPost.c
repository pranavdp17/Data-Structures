#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;
int len;
char exp[MAX];
char post[MAX];

void push(char a)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    stack[++top] = a;
}

char pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}

int pred(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

void infix()
{
    exp[len] = ')';
    int i = 0, j = 0;
    push('(');
    char c = exp[i];
    while (c != '\0')
    {
        c = exp[i++];
        switch (c)
        {
        case '(':
            push('(');
            break;
        case ')':
            while (stack[top] != '(')
            {
                post[j++] = pop();
            }
            pop();
            break;
        case '+':
        case '^':
        case '/':
        case '*':
        case '-':
            while (pred(stack[top]) >= pred(c))
            {
                post[j++] = pop();
            }
            push(c);
            break;
        default:
            post[j++] = c;
            break;
        }
    }
}

int main()
{
    printf("Enter Infix Expression : \n");
    scanf("%s", exp);
    len = strlen(exp);
    exp[len] = ')';
    infix();
    printf("Postfix Expression : %s", post);
    return 0;
}
