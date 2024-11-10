#include <stdio.h>

void findMaxMin(int arr[], int size, int *max, int *min) {
    if (size <= 0) return; 

    *max = arr[0]; 
    *min = arr[0]; 

    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i]; 
        }
        if (arr[i] < *min) {
            *min = arr[i]; 
        }
    }
}

int main() {
    int size;

   
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Array size must be positive.\n");
        return 1; 
    }

    int arr[size];

    
 printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;
    findMaxMin(arr, size, &max, &min); // Call the function to find max and min

    // Output the results
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}