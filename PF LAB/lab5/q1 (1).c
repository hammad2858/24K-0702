#include <stdio.h>
int main(){
	int age;
	printf("Enter age:");
	scanf("%d",&age);
	if (age <= 12) {
        printf("You are a child.\n");
    } else if (age <= 18) {
        printf("You are a teenager.\n");
    } else 
	if (age <= 64) {
        printf("You are an adult.\n");
    } else {
        printf("You are a senior.\n");
    }

    return 0;
} 
