#include <stdio.h>

// Function to demonstrate Call by Value
void callByValue(int a)
{
    // Modify the copied value
    a = a + 10;

    printf("\nInside Function:\n");
    printf("Value of a = %d\n", a);
}

int main()
{
    int a;

    // Read the value of a
    printf("Enter the value of a: ");
    scanf("%d", &a);

    // Display original value before function call
    printf("\nBefore Function Call:\n");
    printf("Value of a = %d\n", a);

    // Call function by passing the value of a
    callByValue(a);

    // Display value after function call
    printf("\nAfter Function Call:\n");
    printf("Value of a = %d\n", a);

    return 0;
}