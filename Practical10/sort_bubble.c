#include<stdio.h>
#include<conio.h>

#define MAX 5

void sort_bubble(int arr[MAX]){
    int temp;

    for(int i = 0; i < MAX - 1; i++){
        for(int j = 0; j < MAX-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[MAX];

    for(int i = 0; i < MAX; i++){
        printf("Enter a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    sort_bubble(arr);

    printf("Sorted array: ");
    for(int i = 0; i < MAX; i++){
        printf("%d ", arr[i]);
    }
    return 0; 
}