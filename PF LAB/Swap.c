#include <stdio.h>

int main(){
    int num1, num2, swap;
	
	printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
	
	printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Swapping the values//
    swap = num1;
    num1 = num2;
    num2 = swap;

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
	
} 
