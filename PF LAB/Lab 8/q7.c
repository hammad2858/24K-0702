#include <stdio.h>

int main() {
    int matrix1[3][3], matrix2[3][3], prod[3][3];
    int i, j, k;

    
    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    
    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            prod[i][j] = 0;
            for (k = 0; k < 3; k++) {
                prod[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    
    printf("Resultant matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", prod[i][j]);
        }
        printf("\n");
    }

    return 0;
}