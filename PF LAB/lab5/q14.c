// Bank_OF_FAST Loan Eligibility criteria :
    // - Age must be at least 18
    // - Annual income must be at least Rs. 50,000
    // - Credit score must be at least 500
#include <stdio.h>
int main(){
    int age,income,credit_score,Eligible;
    
    printf("Enter Age :");
    scanf("%d",&age);
    
    printf("Enter Income :");
    scanf("%d",&income);
    
    printf("Enter credit score :");
    scanf("%d",&credit_score);
    
Eligible = (age>=18) && (income >= 50000) && (credit_score>=500);
 if (Eligible) {
        printf("You are eligible for FAST'S Loan.\n");
    } else {
        printf("You are not eligible for FAST'S loan.\n");
    }

    return 0;
    
    
}