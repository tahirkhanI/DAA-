#include <stdio.h> 
void selectionSort(int arr[], int beginIndex, int size){
	int i;
	if(beginIndex>=size-1){
		return;
	}
	int minIndex=beginIndex;
	for(i=beginIndex; i<size; i++){
		if(arr[i]<arr[minIndex] ){
			minIndex=i;
		}
	}
	int temp=arr[minIndex];
	arr[minIndex]=arr[beginIndex];
	arr[beginIndex]=temp;
	
	selectionSort(arr,beginIndex+1,size);
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
	selectionSort(arr,0,n);
	printf("The sorted array : ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0; 
}
