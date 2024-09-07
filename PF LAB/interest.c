#include <stdio.h>

int main() {
    float principle, rate, time, interest, amount;

    
    printf("Note: Principle must be between 100 Rs. to 1,000,000 Rs.\n");
    printf("Rate of interest must be between 5% to 10%\n");
    printf("Time period must be between 1 to 10 years\n");

    
    printf("Enter the principle amount (in Rs.): ");
    scanf("%f", &principle);

    

    
    printf("Enter the rate of interest (in percentage): ");
    scanf("%f", &rate);

   

   
    printf("Enter the time period (in years): ");
    scanf("%f", &time);

    
    
    interest = (principle * rate * time) / 100;

    amount = principle + interest;

    /* Display results */
    printf("The interest is %.2f Rs.\n", interest);
    printf("The amount is %.2f Rs.\n", amount);

    return 0;
}