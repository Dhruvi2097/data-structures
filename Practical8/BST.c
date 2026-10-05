#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
// Create a new node
struct node* createNode(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into BST
void insert(int data)
{
    struct node *newNode;
    newNode = createNode(data);
    struct node *temp, *prev;

    if(root == NULL){
        root = newNode;
        return;
    }

    temp = root;
    while(temp != NULL){
        prev = temp;
        if(temp ->data > data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    if(prev->data > data){
        prev->left = newNode;
    }
    else{
        prev->right = newNode;
    }
    
}

// Inorder: Left -> Root -> Right
void inorder(struct node *nd)
{
    if(nd == NULL){
        return;
    }
    inorder(nd->left);
    printf("%d ", nd->data);
    inorder(nd->right);
}

// Preorder: Root -> Left -> Right
void preorder(struct node *nd)
{
   if(nd == NULL){
        return;
   }

   printf("%d ", nd->data);
   preorder(nd->left);
   preorder(nd->right);
}

// Postorder: Left -> Right -> Root
void postorder(struct node *nd)
{
    if(nd == NULL){
        return;
    }
    postorder(nd->left);
    postorder(nd->right);
    printf("%d ", nd->data);
}

int main()
{
    int n, choice;

    while(1){
        printf("\n1. Insert node");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n Enter the data to insert: ");
                scanf("%d", &n);
                insert(n);
                break;
            case 2:
                printf("\n Inorder Traversal: ");
                inorder(root);
                break;
            case 3:
                printf("\n Preorder Traversal: ");
                preorder(root);
                break;
            case 4:
                printf("\n Postorder Traversal: ");
                postorder(root);
                break;
            case 5:
                printf("\n Exiting...");
                exit(0);
            default:
                printf("\n Invalid choice! please try again.");
                
        }
    }
    return 0;
}