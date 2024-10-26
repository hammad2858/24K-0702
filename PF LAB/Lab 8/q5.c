#include <stdio.h>

int main() {
    int i,j,num;
    printf("Enter a Number:");
    scanf("%d",&num);
    
    for (i=num;i>=1;i--){
        for (j=1;j<=i;j++){
            if (j % 2 != 0){
                printf(" %d ",j);
            }// if ends
        }// for j ends
        printf("\n");
    }// for i ends
    
    return 0;
}