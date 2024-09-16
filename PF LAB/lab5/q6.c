#include <stdio.h>

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    (number > 0) ? printf("Positive\n") : (number < 0) ? printf("Negative\n") : printf("Zero\n");

    return 0;
}
