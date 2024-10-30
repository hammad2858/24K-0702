

#include <stdio.h>

int main()
{
 int a[5],i;
 for (i=0;i<5;i++){
     printf("Enter elements");
     scanf("%d",&a[i]);
 }//  loop ends 
 
 int smallest = a[0];
 int sec_smallest=a[1];
 
 for (i=2;i<5;i++){
     if (a[i]<smallest){
         sec_smallest = smallest;
         smallest = a[i];
     }// if ends
     
     else if (a[i]<sec_smallest && a[i]!=smallest){
         sec_smallest = a[i];
     }// else if ends
 }// loop ends
  printf("Second smallest element is : %d ",sec_smallest);
 
 
    return 0;
}