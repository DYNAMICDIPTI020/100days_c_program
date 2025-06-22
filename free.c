#include <stdio.h>

int main() {
    int array[5];

   
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }

   
    printf("The elements of the array are:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
