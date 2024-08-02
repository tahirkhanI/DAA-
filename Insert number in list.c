#include <stdio.h>

void insert(int arr[], int n, int num) {
    int i = n - 1;
    while (i >= 0 && arr[i] > num) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = num;
}

void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {1, 2, 4, 5, 6}; 
    int n = 5; 
    int num = 3; 
    printf("Original array: ");
    printArray(arr, n);
    insert(arr, n, num);
    n++;
    printf("Array after insertion: ");
    printArray(arr, n);

    return 0;
}
