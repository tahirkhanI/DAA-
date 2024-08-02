#include<stdio.h>
int main(){
	int n,arr[n],i;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int min=arr[0];
	int max=arr[0];
	for(i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}
	printf("The array elements are :");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nMax = %d\n",max);
	printf("Min = %d",min);
	return 0;
}
