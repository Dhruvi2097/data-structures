#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Function declarations
void push(int);
int pop();
void peek();
void display();

int main()
{
    int choice, x;

    while(1)
    {
        printf("\n===== STACK OPERATIONS =====\n");
        printf("1. Push Operation\n");
        printf("2. Pop Operation\n");
        printf("3. Peek Operation\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                x = pop();
                if(x != -1)
                {
                    printf("Popped element = %d\n", x);
                }
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program Ended.\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

// Function to insert an element into stack
void push(int x)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("Element %d pushed successfully.\n", x);
    }
}

// Function to remove an element from stack
int pop()
{
    int x;

    if(top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        x = stack[top];
        top--;
        return x;
    }
}

// Function to display the top element
void peek()
{
    if(top == -1)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Top element = %d\n", stack[top]);
    }
}

// Function to display all stack elements
void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}