#include<stdio.h>
int main(){
	int n,i;
	int arr[n];
	printf("Enter number of elements in an array : ");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int max=arr[0];
	for(i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	printf("The largest element is %d",max);
	return 0;
}
