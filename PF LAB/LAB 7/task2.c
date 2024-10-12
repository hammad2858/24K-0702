#include <stdio.h>
int main(){
    int num,i;
    printf("enter a number :");
    scanf("%d",&num);
    
    int n[num];
    printf("Enter elements : ");
    for(i=0;i<num;i++){
        scanf("%d",&n[i]);
    }
    for (i = num - 1; i >= 0; i--) {
        printf("%d ", n[i]);
    }
    
    
return 0;
}