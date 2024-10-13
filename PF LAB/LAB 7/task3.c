#include <stdio.h>
int main(){
	int a[]={4,1,6,8,10,21,8,9,2,6};
	int size,i,max,min;
	size = sizeof(a)/sizeof(a[0]);
	max = a[0];
	min = a[0];
	for (i=0;i<size;i++){
		if(a[i]<min){
			min = a{i};
		}
		if (a[i]>max){
			max = a[i];
		}
	}
		printf("%d \n",min);
		printf("%d \n",max);
	
	return 0;
}