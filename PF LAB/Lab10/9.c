#include <stdio.h>

void bubbleSort(int a[], int n) {
   
    if (n == 1) {
        return;
    }

    
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }

    bubbleSort(a, n - 1);
}

void printArray(int b[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
