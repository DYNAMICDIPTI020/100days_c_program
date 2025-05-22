#include <stdio.h>

int main() {
    int n, i, key, lb , ub, mid;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);

    lb = 0;
    ub = n - 1;

    while (lb <= ub) {
        mid = (lb + ub) / 2;

        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return 0;
        } else if (arr[mid] < key) {
            lb = mid + 1;
        } else {
            ub = mid - 1;
        }
    }

    printf("Element not found\n");
    return 0;
}