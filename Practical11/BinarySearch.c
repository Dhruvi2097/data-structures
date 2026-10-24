#include <stdio.h>
#define MAX 7
int search_bin(int arr[MAX], int x){
    int low, high, mid;
    low = 0;
    high = MAX - 1;
    while (low <= high){
        mid = (low + high) / 2;
        if (arr[mid] > x){
            high = mid - 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    int index;
    int arr[MAX], x;

    for(int i = 0; i < MAX; i++){
        printf("Enter a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    index = search_bin(arr, x);

    if(index == -1){
        printf("Element not found in the array.\n");
    }
    else{
        printf("Element found at index: %d\n", index);
    }

    return 0;

}