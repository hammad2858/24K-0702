#include <stdio.h>

int main() {
    
 int num,count = 0;
 
 printf("enter number : ");
 scanf("%d",&num);
 
  while (num!=0) {
      num = num/10;
      count = count+1;
  }
  if (count>1){
      printf("Multiple digit number");
  }
 else {
     printf("Not a multiple digit number");
} 
return 0;
}
