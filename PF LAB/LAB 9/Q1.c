#include <stdio.h>
// func
int prod (int a , int b){
 int c = a*b;
 printf(" product : %d ",c);
    return c;
}

int main(){
    int x,y;
 printf("Enter Two numbers : ");
 scanf("%d %d",&x,&y);
 prod (x,y);
return 0;
}