#include<stdio.h>

#define MAX 5

void sort_selection(int arr[MAX]){
    int pos, temp, min;

    for(int i = 0; i < MAX - 1; i++){
        pos = i;
        min = arr[i];

        for(int j = i + 1; j < MAX; j++){
            if(min > arr[j]){
                min = arr[j];
                pos = j;
            }
        }
        if(pos != i){
            temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
}

int main(){
    int arr[MAX]; 

    for(int i = 0; i < MAX; i++){
        printf("Enter a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    sort_selection(arr);

    printf("sorted array: ");
    for(int i = 0; i < MAX;  i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
