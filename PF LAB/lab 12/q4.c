#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of the elements: %d\n", sum);

    
    free(arr);

    return 0;
}