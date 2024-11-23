#include<stdio.h>
#define MAX_TEMP 60

void checktemp(float temp){
    static int count = 0;
    if(temp>MAX_TEMP){
        count ++;
        printf("Temperature %.2f°C exceeds the maximum limit of %.2f°C.\n", temp, MAX_TEMP);
        }// if ends 
        else{
            printf("Temperature %.2f°C is within the allowable limit.\n", temp);
        }
        printf("%d times temp exceeded !\n ",count);
}
int main() {
    double temp1, temp2, temp3;

    printf("Enter first temperature (in Celsius): ");
    scanf("%lf", &temp1);
    checktemp(temp1);

    printf("Enter second temperature (in Celsius): ");
    scanf("%lf", &temp2);
    checktemp(temp2);

    printf("Enter third temperature (in Celsius): ");
    scanf("%lf", &temp3);
    checktemp(temp3);

    return 0;
}