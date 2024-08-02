#include <stdio.h>
#include <limits.h>
void findMinMax(int arr[], int left, int right, int *min, int *max) {
    if (left == right) {
        *min = *max = arr[left];
    }
    else if (right == left + 1) {
        if (arr[left] < arr[right]) {
            *min = arr[left];
            *max = arr[right];
        } else {
            *min = arr[right];
            *max = arr[left];
        }
    }
    else {
        int mid = (left + right) / 2;
        int min1, max1, min2, max2;

        findMinMax(arr, left, mid, &min1, &max1);
        findMinMax(arr, mid + 1, right, &min2, &max2);

        if (min1 < min2) {
            *min = min1;
        } else {
            *min = min2;
        }

        if (max1 > max2) {
            *max = max1;
        } else {
            *max = max2;
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, 0, size - 1, &min, &max);

    printf("Minimum value in the array: %d\n", min);
    printf("Maximum value in the array: %d\n", max);

    return 0;
}

