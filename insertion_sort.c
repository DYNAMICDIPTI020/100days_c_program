#include <stdio.h>
int main() {
    int i, j, key, size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }
    for(i = 1; i < size; i++) 
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Sorted array:\n");
    for(i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
