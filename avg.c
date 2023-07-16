#include<stdio.h>
int main(){
	int n,i,arr[n],avg=0,sum=0;
	printf("enter the number of integers:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		sum=sum+i;
	}
	printf("%d",sum);
	
	return 0;
}
