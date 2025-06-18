#include <stdio.h>

int main() {
    int i, n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    int low = 0, high = n - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(A[mid] == x) {
            printf("Element found at index %d\n", mid);
            break;
        } else if(A[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if(low > high) {
        printf("Element not found in the array.\n");
    }

    return 0;
}
