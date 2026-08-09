#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n, i;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n integers
    ptr = (int *)malloc(n * sizeof(int));

    // Check whether memory allocation is successful
    if(ptr == NULL)
    {
        printf("Memory Allocation Failed");
        return 0;
    }

    // Read array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    // Display array elements in reverse order
    printf("\nArray in Reverse Order:\n");
    for(i = n - 1; i >= 0; i--)
    {
        printf("%d ", *(ptr + i));
    }

    // Free the allocated memory
    free(ptr);

    return 0;
}