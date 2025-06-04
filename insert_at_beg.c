#include <stdio.h>

#define MAX 100 // Maximum capacity of the array

int main() {
    int arr[MAX]; // Array declaration
    int size;

    printf("Enter the number of elements in the array (max %d): ", MAX);
    scanf("%d", &size);

    if (size > MAX) {
        printf("Size exceeds maximum capacity.\n");
        return 1;
    }

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int newElement;
    printf("Enter the new element to insert at the beginning: ");
    scanf("%d", &newElement);

    if (size >= MAX) {
        printf("Array is full, cannot insert element.\n");
    } else {
        // Shift elements to the right
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        // Insert the new element at the beginning
        arr[0] = newElement;
        size++;
    }

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
