#include <stdio.h>
int main(){
    int i,j,num;
    printf("Enter number :");
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        for (j=1;j<=i;j++){
            printf("%d ",j);
        }// for j ends
        printf("\n");
    }// for i ends
    
    
    return 0;
}
