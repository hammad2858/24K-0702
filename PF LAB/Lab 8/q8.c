#include <stdio.h>
int main(){
	int i,j,k,row;
	printf("Enter rows :");
	scanf("%d",&row);
	// UPPER HALF
	for (i=1;i<=row;i++){
		for (j=1;j<=row-i;j++){
			printf(" ");
		}//for j ends
		for (k=1;k<=2*i-1;k++){
			printf("*");
		}// for k ends
		printf("\n");
	}// for i ends
	
	// LOWER HALF
	for (i=row-1;i>=1;i--){
		for (j=1;j<=row-i;j++){
			printf(" ");
		}// for j ends
		for (k=1;k<=2*i-1;k++){
			printf("*");
		}// for k ends
		printf("\n");
	}// for i ends
	
	
	return 0;
}