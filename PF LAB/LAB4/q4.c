#include <stdio.h>

int main() {
    float cost, discount, savedAmount, amountAfterDiscount;

    printf("Enter the cost of shopping (minimum 500): ");
    scanf("%f", &cost);

    if (cost < 500) {
        printf("Minimum cost for discount is 500.\n");
    } else {
        if (cost < 2000) {
            discount = 0.05 * cost;
        } else if (cost < 4000) {
            discount = 0.10 * cost;
        } else if (cost < 6000) {
            discount = 0.20 * cost;
        } else {
            discount = 0.35 * cost;
        }

        
        savedAmount = discount;
        amountAfterDiscount = cost - savedAmount;

        printf("cost: %.2f\n", cost);
        printf("Saved Amount: %.2f\n", savedAmount);
        printf("Amount After Discount: %.2f\n", amountAfterDiscount);
    }

    return 0;
}