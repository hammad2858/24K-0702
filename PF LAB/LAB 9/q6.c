#include <stdio.h>

void swapIntegers(int a, int b) {
    int c = a;
    a = b;
    b = c;
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Before swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    swapIntegers(num1, num2);

    printf("After swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}