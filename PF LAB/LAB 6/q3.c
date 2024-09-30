#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num<= 1) {
        printf("%d is composite number.\n", num);
        return 0;
    }
    if (num <= 3) {
        printf("%d is a prime number.\n", num);
        return 0;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        printf("%d is composite number.\n", num);
        return 0;
    }

    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) {
            printf("%d is composite number.\n", num);
            return 0;
        }
        i += 6;
    }

    printf("%d is a prime number.\n", num);
    return 0;
}