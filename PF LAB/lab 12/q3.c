#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int **matrix1, int **matrix2, int m, int n, int o, int **result) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < o; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int m, n, o;

    printf("Enter the dimensions of the first matrix (m x n): ");
    scanf("%d %d", &m, &n);

    printf("Enter the dimensions of the second matrix (n x o): ");
    scanf("%d", &o);

    
    int **matrix1 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix1[i] = (int *)malloc(n * sizeof(int));
    }

    int **matrix2 = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix2[i] = (int *)malloc(o * sizeof(int));
    }

    int **result = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        result[i] = (int *)malloc(o * sizeof(int));
    }

    
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < o; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    
    multiplyMatrices(matrix1, matrix2, m, n, o, result);

    
    printf("Product of the matrices:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < o; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    
    for (int i = 0; i < m; i++) {
        free(matrix1[i]);
        free(result[i]);
    }
    free(matrix1);
    free(result);

    for (int i = 0; i < n; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}