#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, last_digit;

    while (number > 0) {
        last_digit = number % 10;
        number = number / 10;
        decimal += last_digit * base;
        base = base * 2;
    }
    return decimal;
}

int DecimalToBinary(int number) {
    int binary = 0, base = 1;

    while (number > 0) {
        binary += (number % 2) * base;
        number /= 2;
        base *= 10;
    }
    return binary;
}

void DecimalToHexadecimal(int number) {
    char hex[20];
    int i = 0;

    if (number == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    while (number != 0) {
        int temp = number % 16;
        if (temp < 10) {
            hex[i++] = temp + '0';
        } else {
            hex[i++] = temp - 10 + 'A';
        }
        number /= 16;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    putchar('\n');
}

void HexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0;
    int base = 1;
    int len = strlen(hexNumber);

    for (int i = len - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimal += (hexNumber[i] - '0') * base;
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            decimal += (hexNumber[i] - 'A' + 10) * base;
        }
        base *= 16;
    }
    printf("Decimal: %d\n", decimal);
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexNumber[]) {
    int decimal = 0;
    HexadecimalToDecimal(hexNumber); // Print decimal equivalent for verification
    int base = 1;

    // Convert to binary
    int binary = DecimalToBinary(decimal);
    printf("Binary: %d\n", binary);
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("7. Exit\n");
}

int main() {
    int choice, number;
    char hexNumber[20];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal: %d\n", BinaryToDecimal(number));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", DecimalToBinary(number));
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;
            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
