#include <stdio.h>

int main() {
    float dist, fuel_avg, fuel_price1, fuel_price2, total_fuel_consumed, total_fuel_cost, total_dist;
    printf("Enter the car's fuel average (in km/l): ");
    scanf("%f", &fuel_avg);

    printf("Fuel average must be a positive number. Please enter again: ");
    scanf("%u", &fuel_avg);
   
    dist = 1207; 
    fuel_price1 = 118; 
    fuel_price2 = 123; 

    total_dist = 2 * dist; 

    total_fuel_consumed = total_distance / fuel_avg;
	
    total_fuel_cost = total_fuel_consumed * ((fuel_price1 + fuel_price2) / 2);
	
    printf("Total fuel consumed for the round trip is", total_fuel_consumed);
    printf("Total fuel cost for the round trip is ", total_fuel_cost);

    return 0;
}