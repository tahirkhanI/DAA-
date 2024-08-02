#include<stdio.h>
void bubbleSort(int arr[],int endIndex) {
	int i;
	if(endIndex == 0){
		return;
	}
	for(i=0;i<endIndex;i++){
		if(arr[i]>arr[i+1] ){
			int temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}
	}
	bubbleSort(arr, endIndex-1);
}

int main() 
{
	int n,arr[n],i;
	printf("Enter number of elements in array : ");
	scanf("%d",&n);
	printf("Enter array elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr,n-1);
	printf("Sorted Array : ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0; 
}
