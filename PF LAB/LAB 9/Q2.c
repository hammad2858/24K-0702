// Write a function that checks if a given number is even or odd.
#include <stdio.h>
// func
 int func(int num){
    if (num%2==0){
        printf("Even");
    }// if ends
    else {
        printf("Odd");
    }
     return 0;
 }

int main (){
 int n;
 printf("Enter  a Number : ");
 scanf("%d",&n);
 func (n);
    return 0;
}
 