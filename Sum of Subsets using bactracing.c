#include <stdio.h>

#define MAX 100

void printSolution(int subset[], int size) {
	int i;
    for ( i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}
void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int total, int nodeIndex, int target) {
    if (total == target) {
        printSolution(subset, subsetSize);
        return;
    }

    if (nodeIndex == n) {
        return;
    }
    subset[subsetSize] = set[nodeIndex];
    sumOfSubsets(set, subset, n, subsetSize + 1, total + set[nodeIndex], nodeIndex + 1, target);
    sumOfSubsets(set, subset, n, subsetSize, total, nodeIndex + 1, target);
}

int main() {
    int n, target;
    int set[MAX], subset[MAX];

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    int i;
    for ( i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets with the given sum are:\n");
    sumOfSubsets(set, subset, n, 0, 0, 0, target);

    return 0;
}

