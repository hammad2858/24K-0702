#include <stdio.h>

int main() {
  int a=1,b=2,i,c;
  printf("%d %d ", a, b);
  for (i=0;i<7;i++){
      c = a*b;
     printf("%d ",c);
     a=b;
     b=c;
  }
printf("%d \n");
    return 0;
}