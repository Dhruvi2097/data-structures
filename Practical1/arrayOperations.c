#include <stdio.h>
#include<stdlib.h>

// Global array and variable to store the number of elements
int arr[100], n;

// Function declarations
void createArray();
void traverse();
void insertElement();
void deleteElement();
void searchElement();

int main()
{
    int choice;

    // Repeat menu until the user chooses Exit
    while(1)
    {
        // Display menu
        printf("\n===== ARRAY OPERATIONS =====\n");
        printf("1. Create Array\n");
        printf("2. Traverse Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user's choice
        switch(choice)
        {
            case 1:
                createArray();      // Create a new array
                break;

            case 2:
                traverse();         // Display array elements
                break;

            case 3:
                insertElement();    // Insert an element
                break;

            case 4:
                deleteElement();    // Delete an element
                break;

            case 5:
                searchElement();    // Search for an element
                break;

            case 6:
                printf("Program Ended.\n");
                exit(0); // Exit the program

            default:
                printf("Invalid Choice!\n"); // Handle invalid input
        }

    }

    return 0;
}

// Function to create an array
void createArray()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    // Read array elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array Created Successfully.\n");
}

// Function to display array elements
void traverse()
{
    int i;

    // Check if array is empty
    if(n == 0)
    {
        printf("Array is Empty.\n");
        return;
    }

    printf("Array Elements:\n");

    // Print all elements
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Function to insert an element
void insertElement()
{
    int pos, item, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter element: ");
    scanf("%d", &item);

    // Check for valid position
    if(pos < 0 || pos > n)
    {
        printf("Invalid Position.\n");
        return;
    }

    // Shift elements one position to the right
    for(i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert new element
    arr[pos] = item;
    n++; // Increase array size

    printf("Element Inserted Successfully.\n");
}

// Function to delete an element
void deleteElement()
{
    int pos, i;

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    // Check for valid position
    if(pos < 0 || pos >= n)
    {
        printf("Invalid Position.\n");
        return;
    }

    // Shift elements one position to the left
    for(i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--; // Decrease array size

    printf("Element Deleted Successfully.\n");
}

// Function to search an element
void searchElement()
{
    int key, i;

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Search element using linear search
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at position %d\n", i);
            return;
        }
    }

    // If element is not found
    printf("Element not found.\n");
}