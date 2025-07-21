#include <stdio.h>

int main() {
    int n;
    double sum = 0.0;

    // Prompt the user to enter the value of n
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // Check if n is a positive integer
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Calculate the sum of the series 1/1 + 1/2 + 1/3 + ... + 1/n
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }

    // Print the result
    printf("The sum of the series is: %.6f\n", sum);

    return 0;
}
