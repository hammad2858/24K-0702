#include <stdio.h>




double convertMetersToKilometers(double meters) {
    static int callCount = 0;  
    callCount++;                

    printf("Function called %d times.\n", callCount);
    return meters * 0.001;  
}

int main() {
    double meters;
    char choice;

    do {
        printf("Enter distance in meters: ");
        scanf("%lf", &meters);
        double kilometers = convertMetersToKilometers(meters);
        printf("%.2f meters is equal to %.2f kilometers.\n", meters, kilometers);

        printf("Do you want to convert another distance? (y/n): ");
        scanf(" %c", &choice);  
    } while (choice == 'y' || choice == 'Y');

    return 0;
}