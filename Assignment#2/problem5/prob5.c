#include <stdio.h>

void horizontal_histogram(int values[], int count) {
    printf("Horizontal Histogram:\n");
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", values[i]);
        for (int j = 0; j < values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void vertical_histogram(int values[], int count) {
    int max_value = values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    printf("Vertical Histogram:\n");
    for (int i = max_value; i > 0; i--) {
        for (int j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Print the base of the histogram
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() {
    int values[] = {3, 5, 1, 4};
    int count = sizeof(values) / sizeof(values[0]);

    horizontal_histogram(values, count);
    vertical_histogram(values, count);
    return 0;
}
