#include <stdio.h>

int main() {
    int customerId, unitsConsumed;
    char customerName[100];
    float unitCharge, totalBill, surcharge;

    printf("Enter Customer ID: ");
    scanf("%d", &customerId);

    printf("Enter Customer Name: ");
    scanf("%c", &customerName);

    printf("Enter Units Consumed: ");
    scanf("%d", &unitsConsumed);

    if (unitsConsumed <= 199) {
        unitCharge = 16.20;
    } else if (unitsConsumed < 300) {
        unitCharge = 20.10;
    } else if (unitsConsumed < 500) {
        unitCharge = 27.10;
    } else {
        unitCharge = 35.90;
    }

    totalBill = unitsConsumed * unitCharge;

    if (totalBill > 18000) {
        surcharge = 0.15 * totalBill;
        totalBill += surcharge;
    }

    printf("\nCustomer ID: %d\n", customerId);
    printf("Customer Name: %s\n", customerName);
    printf("Units Consumed: %d\n", unitsConsumed);
    printf("Total Bill: %.2f\n", totalBill);

    return 0;
}