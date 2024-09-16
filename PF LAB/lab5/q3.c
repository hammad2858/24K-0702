#include <stdio.h>
int main(){
	int num;
	printf("Enter Number:");
	scanf("%d",&num);
	
	if (num%3==0 && num%5==0){
		printf("Divisible by 3 and 5  ");
	}
	else{
		printf("entered Number is not divisible by 3 and 5 both");
	}
	return 0;
	
	
}
