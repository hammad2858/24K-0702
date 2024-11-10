#include <stdio.h>

void calculator(int a, int b, char operator) {
    switch (operator) {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("%d / %d = %d\n", a, b, a / b);
            }
            break;
        default:
            printf("Invalid operation\n");
    }
}

int main() {
    int num1, num2;
    char operator;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter an operation (+, -, *, /): ");
    scanf(" %c", &operator);

    calculator(num1, num2, operator);

    return 0;
}