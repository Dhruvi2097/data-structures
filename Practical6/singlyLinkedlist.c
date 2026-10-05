#include<stdio.h>
#include<stdlib.h>

// struct node *first = null;
struct node{
    int data;
    struct node *next;
};
struct node *first = NULL;
struct node*create_node(int x)
{
    struct node * temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    
}

void display(){
    struct node *t;
    t = first;
    while(t!=NULL){
        printf("%d ", t->data);
        t = t->next;
    }
}

void insert_first(int x){
    struct node *t;
    t = create_node(x);
    if(first == NULL){
        first = t;
    }
    else{
        t->next = first;
        first = t;
    }
}

void insert_last(int x){
    struct node *t, *temp;
    t = create_node(x);
    if(first == NULL){
        first = t;
    }
    else{
        temp = first;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = t;
    }
}

void insert_after(int x, int pos){
    struct node *t, *temp;
    t = create_node(x);
    if(first == NULL){
        first = t;
    }
    else{
        temp = first;
        while(temp->data != pos && temp->next != NULL){
            temp = temp->next;
        }
        if(temp->data == pos){
            t->next = temp->next;
            temp->next = t;        
        }
        else{
            printf("Position not found...!");
        }
    }
}

int delete_position(int pos){
    struct node *temp, *prev;
    if(first == NULL){
        printf("List is empty...!");
        return -1;
    }
    else{
        temp = first;
        while(temp->data != pos && temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        if(temp->data == pos){
            if(temp == first){
                first = first->next;
                int x = temp->data;
                free(temp);
                return x;
            }
            else{
                prev->next = temp->next;
                int x = temp->data;
                free(temp);
                return x;
            }
        }
    }
}
int delete_first(){
    struct node *temp;
    if(first == NULL){
        printf("List is empty...!");
        return -1;
    }
    else{
        temp = first;
        first = first->next;
        int x = temp->data;
        free(temp);
        return x;
    }
}
int delete_last(){
    struct node *temp, *prev;
    if(first == NULL){
        printf("List is empty...!");
        return -1;
    }
    else if(first->next == NULL){
        int x = first->data;
        free(first);
        first = NULL;
        return x;
    }
    else{
        temp = first;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        int x = temp->data;
        free(temp);
        prev->next = NULL;
        return x;
    }
}
void main(){
    int n, choice;

    while(1){
        printf("\n======singly linked list operations======");
        printf("\n1. Insert first");
        printf("\n2. Insert last");
        printf("\n3. Insert after");
        printf("\n4. Delete first");
        printf("\n5. Delete last");
        printf("\n6. Delete position");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\n=========================================");


        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("Enter data: ");
            scanf("%d", &n);
            insert_first(n);
            break;

            case 2:
            printf("the data in linked list: ");
            display();
            break;

            case 3:
            printf("Enter data: ");
            scanf("%d", &n);
            insert_last(n);
            break;

            case 4:
            printf("Deleted data: %d", delete_first());
            break;

            case 5:
            printf("Deleted data: %d", delete_last());
            break;

            case 6:
            printf("Enter position: ");
            scanf("%d", &n);
            printf("Deleted data: %d", delete_position(n));
            break;

            case 7:
            printf("the data in linked list: ");
            display();
            break;

            case 8:
            printf("\n Program ended successfully...");
            exit(0);


            default:
            printf("Invalid choice...!");
        }
    }
}