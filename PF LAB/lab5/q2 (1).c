#include <stdio.h>
int main(){
	int num;
	printf("Enter a number;\n");
	scanf("%d",&num);
	
	
	if (num > 0) {
        if (num % 2 == 0) {
            printf("Positive even number\n");
        } else {
            printf("Positive odd number\n");
        }
    } else if (num < 0) {
        printf("Negative number\n");
    } else {
        printf("Zero\n");
    }

    return 0;
}
	
      	
      	
      	
      	



