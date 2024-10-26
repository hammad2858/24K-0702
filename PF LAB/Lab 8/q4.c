
#include <stdio.h>

int main() {
    int start,end,i,j,prime;
    printf("Enter Starting and Ending Numbers ");
    scanf("%d %d",&start,&end);
    for (i=start;i<=end;i++){
        prime =1;
        for (j=2;j*j<=i;j++){
            if(i%j==0){
                prime=0;
            }//if ends
        }// for j ends
        if (prime==1){
            printf(" %d  ",i);
        }// 2 if ends 
        
    }// for i ends
    
    return 0;
}