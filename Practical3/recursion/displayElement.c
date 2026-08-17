//display array elements using recursion
#include<stdio.h>

void displayElement(int arr[], int n){
    if(n == 0){
        return;
    }
    displayElement(arr, n - 1);
    printf("%d ", arr[n-1]);
}

int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
   
    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("The array elements are: ");
    displayElement(arr, n);
    return 0;
}