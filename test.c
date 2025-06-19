#include <stdio.h>

int main() {
    int n, i = 0, num;

    // Prompt user for the number of integers they will enter
    printf("How many numbers will you enter? ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    while (i < n) {
        scanf("%d", &num);
        // Check if the number is even
        if (num % 2 == 0) {
            printf("%d is even.\n", num);
        }
        i++;
    }

    return 0;
}
