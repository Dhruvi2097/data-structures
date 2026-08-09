#include <stdio.h>

// Function to demonstrate Call by Reference
void callByReference(int *b)
{
    // Modify the original value using pointer
    *b = *b + 10;

    printf("\nInside Function:\n");
    printf("Value of b = %d\n", *b);
}

int main()
{
    int b;

    // Read the value of b
    printf("Enter the value of b: ");
    scanf("%d", &b);

    // Display original value before function call
    printf("\nBefore Function Call:\n");
    printf("Value of b = %d\n", b);

    // Call function by passing the address of b
    callByReference(&b);

    // Display value after function call
    printf("\nAfter Function Call:\n");
    printf("Value of b = %d\n", b);

    return 0;
}