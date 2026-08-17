#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 5
 
int queue[MAX];
int front =-1, rear =-1;

//function declaration
void enQueue(int);
int deQueue();
void display();

int main(){
    int choice, n;
    
    while(1){
        printf("\n================================");
        printf("\n 1.enqueue operation");
        printf("\n 2.dequeue operation");
        printf("\n 3.dispaly elements of queue");
        printf("\n 4.exit");
        printf("\n================================");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n Enter element you want to add: ");
                scanf("%d", &n);
                enQueue(n);
                break;
            case 2:
                n = deQueue();
                printf("\n poped element is: %d", n);
                break;
            case 3:
                printf("Elements in queue are:\n");
                display();
                break;
            case 4:
                printf("program ended sucessfully...");
                exit(0);
            default:
                printf("Invalid choice..");

        }
    }
    return 0;
}

void enQueue(int n){
    if(front == ((rear + 1)%MAX)){
        printf("\n queue overflow....");
        exit(0);
    }
    rear = (rear+1) % MAX;
    queue[rear] = n;
    if(front == -1){
        front = 0; 
    }
}

int deQueue(){
    int temp;

    if(front == -1){
        printf("\n queue underflow...");
        exit(0);
    }

    temp = queue[front];

    if(front == rear){
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return temp;
}

void display(){
    int i;

    if(front == -1){
        printf("\nNo elements in queue...");
        return;
    }

    i = front;

    while(1){
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}