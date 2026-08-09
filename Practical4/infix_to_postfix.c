#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function declarations
void push(char);
char pop();
int precedence(char);

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++)
    {
        ch = infix[i];

        // If operand, add it to postfix
        if(isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }

        // If opening bracket, push into stack
        else if(ch == '(')
        {
            push(ch);
        }

        // If closing bracket, pop until opening bracket
        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }

            pop();
        }

        // If operator
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j] = pop();
                j++;
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

// Function to push an element
void push(char ch)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

// Function to pop an element
char pop()
{
    char ch;

    if(top == -1)
    {
        return '\0';
    }
    else
    {
        ch = stack[top];
        top--;
        return ch;
    }
}

// Function to check operator precedence
int precedence(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    else if(ch == '^' || ch == '$')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}