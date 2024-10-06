#include <stdio.h>

int main() {
    int n = 65536,i,d=2;

    for (i = 0; i < 9; i++) {
        printf("%d ", n);
        n = n/d;
        d++;
    }

    printf("%d\n", n);

    return 0;
}