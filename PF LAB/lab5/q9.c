//q9//
#include <stdio.h>
int main(){
int year;

 printf("Enter year :");
 scanf("%d",&year);
 
 if (year%4 == 0 && year%100 != 0 || year%400 == 0){
     printf(" Leap Year : %d",year);
} 
else {
    printf("not a leap year : %d",year);
}
 return 0;
}