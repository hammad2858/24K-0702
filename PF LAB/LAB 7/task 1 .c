#include <stdio.h>
int main() {
 int num [10],sum,i;
 printf("Enter Numbers (0-9) : ");
  for (i=0;i<10;i++){
      scanf("%d",&num[i]);
      sum += num[i];
  }
  printf("sum: %d ",sum);
    return 0;
}