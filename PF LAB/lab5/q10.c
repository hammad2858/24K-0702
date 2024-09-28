#include <stdio.h>

int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 9) {
        sum = 0;
        while (num != 0) {
            sum =(sum + num) % 10;
            num =num / 10; 
        }
        num = sum;
    }

    printf("The sum of digits : %d\n", num);

    return 0;
}