#include <stdio.h>

#define MAX_SIZE 10

int arr[MAX_SIZE];
int size = 0; 

void displayArray() {
    int i;
    printf("Current array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement() {
    int element, pos;
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert (1-%d): ", size);
    scanf("%d", &pos);
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position. Please enter a value between 1 and %d.\n", size + 1);
        return;
    }
   
    for (int i = size; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = element;
    size++;
    printf("Element inserted successfully.\n");
}

int main() {
    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1. Insert element\n");
        printf("2. Display array\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertElement();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}