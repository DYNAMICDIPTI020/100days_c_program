#include <stdio.h>

int main() {
    int count = 200;

    
    for (int i = 0; i < count; i++) {
        
        int oddNumber = 2 * i + 1;
        printf("%d ", oddNumber);
    }
    printf("\n"); // Print a newline at the end
    return 0;
}