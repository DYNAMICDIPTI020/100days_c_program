#include <stdio.h>

#define MAX 100

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

  
    while (start < end) {
    
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

      
        start++;
        end--;
    }
}

int main() {
    int arr[MAX], size, i;

 
    printf("Enter the size of the array (max %d): ", MAX);
    scanf("%d", &size);


    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

   
    reverseArray(arr, size);

  
    printf("Reversed array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}