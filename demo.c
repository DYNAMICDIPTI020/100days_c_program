#include <stdio.h>

// Function to find GCD using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Alternative iterative approach
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, result;
    
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    
    // Make sure we work with positive numbers
    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;
    
    // Calculate GCD using recursive method
    result = gcd(num1, num2);
    
    printf("GCD of %d and %d is: %d\n", num1, num2, result);
    
    // Demonstrate iterative method as well
    printf("GCD using iterative method: %d\n", gcd_iterative(num1, num2));
    
    return 0;
}