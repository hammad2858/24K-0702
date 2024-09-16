#include <stdio.h>

int countOnes(int num) {
    int count = 0;

    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }

    return count;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int onesCount = countOnes(num);
    printf("Number of 1s in the binary representation: %d\n", onesCount);

    return 0;
}
