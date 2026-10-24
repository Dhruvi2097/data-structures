#include <stdio.h>
#include <stdlib.h>

struct cll {
    int no;
    struct cll *next;
};

struct cll *first = NULL;

// Function Prototypes
void insert_front(int x);
void insert_end(int x);
void insert_after(int x, int target);
void delete_first();
void delete_last();
void delete_after(int target);
void display();

int main() {
    int choice, no, target;

    while (1) {
        printf("\n*****************************");
        printf("\n Menu for Singly Circular Linked List...");
        printf("\n 1. Insert at beginning");
        printf("\n 2. Insert at end");
        printf("\n 3. Insert after a given node");
        printf("\n 4. Delete first node");
        printf("\n 5. Delete last node");
        printf("\n 6. Delete node after a given node");
        printf("\n 7. Display all nodes");
        printf("\n 8. Exit");
        printf("\n Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &no);
                insert_front(no);
                break;
            case 2:
                printf("Enter number: ");
                scanf("%d", &no);
                insert_end(no);
                break;
            case 3:
                printf("Enter number and target node value: ");
                scanf("%d %d", &no, &target);
                insert_after(no, target);
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                printf("Enter target node value: ");
                scanf("%d", &target);
                delete_after(target);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("\nProgram terminated successfully.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

void insert_front(int x) {
    struct cll *new1 = (struct cll*)malloc(sizeof(struct cll));
    new1->no = x;

    if (first == NULL) {
        first = new1;
        new1->next = first;
        return;
    }

    struct cll *temp = first;
    while (temp->next != first) {
        temp = temp->next;
    }
    new1->next = first;
    first = new1;
    temp->next = first;
}

void insert_end(int x) {
    struct cll *new1 = (struct cll*)malloc(sizeof(struct cll));
    new1->no = x;

    if (first == NULL) {
        first = new1;
        new1->next = first;
        return;
    }

    struct cll *temp = first;
    while (temp->next != first) {
        temp = temp->next;
    }
    temp->next = new1;
    new1->next = first;
}

void insert_after(int x, int target) {
    if (first == NULL) {
        printf("\nList is empty!");
        return;
    }

    struct cll *temp = first;
    do {
        if (temp->no == target) {
            struct cll *new1 = (struct cll*)malloc(sizeof(struct cll));
            new1->no = x;
            new1->next = temp->next;
            temp->next = new1;
            return;
        }
        temp = temp->next;
    } while (temp != first);

    printf("\nTarget node %d not found!", target);
}

void delete_first() {
    if (first == NULL) {
        printf("\nList is empty!");
        return;
    }

    struct cll *temp = first;
    if (first->next == first) { // Only one node
        free(first);
        first = NULL;
        return;
    }

    struct cll *last = first;
    while (last->next != first) {
        last = last->next;
    }
    first = first->next;
    last->next = first;
    free(temp);
}

void delete_last() {
    if (first == NULL) {
        printf("\nList is empty!");
        return;
    }

    if (first->next == first) { // Only one node
        free(first);
        first = NULL;
        return;
    }

    struct cll *temp = first;
    struct cll *prev = NULL;
    while (temp->next != first) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = first;
    free(temp);
}

void delete_after(int target) {
    if (first == NULL) {
        printf("\nList is empty!");
        return;
    }

    struct cll *temp = first;
    do {
        if (temp->no == target) {
            struct cll *to_delete = temp->next;
            if (to_delete == first) { 
                // The node after target is the first node
                first = first->next;
            }
            temp->next = to_delete->next;
            free(to_delete);
            return;
        }
        temp = temp->next;
    } while (temp != first);

    printf("\nTarget node %d not found!", target);
}

void display() {
    if (first == NULL) {
        printf("\nList is empty!");
        return;
    }

    struct cll *temp = first;
    printf("\nThe CLL is: ");
    do {
        printf("%d -> ", temp->no);
        temp = temp->next;
    } while (temp != first);
    printf("(head)\n");
}
