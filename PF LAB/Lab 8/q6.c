#include <stdio.h>

int main() {
    int matrix[3][3], i, j, row_min, cols_max;
    int saddle_points = 0;

    printf("Enter the elements of the 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        row_min = matrix[i][0];
        for (j = 1; j < 3; j++) {
            if (matrix[i][j] < row_min) {
                row_min = matrix[i][j];
            }
        }

        for (j = 0; j < 3; j++) {
            cols_max = matrix[0][j];
            for (int k = 1; k < 3; k++) {
                if (matrix[k][j] > cols_max) {
                    cols_max = matrix[k][j];
                }
            }

            if (row_min == cols_max) {
                printf("Saddle point  (%d, %d): %d\n", i, j, row_min);
                saddle_points++;
            }
        }
    }

    if (saddle_points == 0) {
        printf("No saddle point \n");
    }

    return 0;
}