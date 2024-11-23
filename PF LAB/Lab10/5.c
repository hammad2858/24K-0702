#include<stdio.h>

int printarray(int a[],int size ){

    if (size ==0){
        return 0;
    }
    printf("%d ",a[0]);
return printarray(a + 1,size - 1);
}

int main(){
    int b[5]={5,6,7,8,9};
    int size;
    size = sizeof(b)/sizeof(b[0]);
    printarray(b,size);
    
}