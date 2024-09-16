#include <stdio.h>
int main(){
	int age;
	int pakistani;
	
	printf("Enter your age : \n");
	scanf("%d",&age);
	printf("Pakistani: \n");
	scanf("%d",&pakistani);
	
	if (age>=18 && pakistani){
		printf("you are eligible to vote");
		
	}
	
	else {
		printf("your are not eligible to vote");
		
	}
	return 0;
}
