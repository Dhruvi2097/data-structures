#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int);
int pop();

int main()
{
    int n;

    printf("Enter total number of elements: ");
    scanf("%d", &n);

    char arr[n];

    printf("Enter postfix expression:\n");

    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }

    printf("Postfix Expression: ");

    for(int i = 0; i < n; i++)
    {
        printf("%c", arr[i]);
    }

    printf("\n");

    for(int i = 0; i < n; i++)
    {
        if(isdigit(arr[i]))
        {
            push(arr[i] - '0');
        }
        else
        {
            int a = pop();
            int b = pop();

            switch(arr[i])
            {
                case '+':
                    push(b + a);
                    break;

                case '-':
                    push(b - a);
                    break;

                case '*':
                    push(b * a);
                    break;

                case '/':
                    push(b / a);
                    break;
            }
        }
    }

    printf("Result: %d\n", pop());

    return 0;
}

void push(int x)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = x;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}