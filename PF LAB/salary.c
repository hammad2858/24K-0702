#include <stdio.h>

int main() {
    float salary, tax_rate, tax, net_salary;

    /* Ask user for salary and tax rate */
    printf("Enter your salary: ");
    scanf("%f", &salary);

    printf("Enter the tax rate (in percentage): ");
    scanf("%f", &tax_rate);

    /* Calculate tax */
    tax = (salary * tax_rate) / 100;

    /* Calculate net salary */
    net_salary = salary - tax;

    /* Display results */
    printf("You have to pay %.2f in tax.\n", tax);
    printf("Your net salary after paying tax is %.2f.\n", net_salary);

    return 0;
}