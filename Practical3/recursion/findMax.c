#include<stdio.h>

int findMax(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int max = findMax(arr, n - 1);
    if (arr[n - 1] > max) {
        max = arr[n - 1];
    }
    return max;
}


int main(){
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i =0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

    int max = findMax(arr, n);
    printf("The maximum element in the array is: %d\n", max);

    return 0; 
}