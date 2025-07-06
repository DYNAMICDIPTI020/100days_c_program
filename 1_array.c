#include "stdio.h"

int main() {
    int rows = 3;
    int columns = 3;
    int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("2D Array Elements:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
