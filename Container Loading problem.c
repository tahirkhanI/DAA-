#include <stdio.h>

#define MAX_ITEMS 100


void printSolution(int solution[], int itemCount) {
    printf("Items included in the solution: ");
    int i;
    for ( i = 0; i < itemCount; i++) {
        if (solution[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

// Backtracking function to solve the container loading problem
void containerLoader(int weights[], int solution[], int itemCount, int maxWeight, int currentWeight, int currentIndex, int *bestWeight) {
    if (currentWeight <= maxWeight && currentWeight > *bestWeight) {
        *bestWeight = currentWeight;
        printSolution(solution, itemCount);
    }

    if (currentIndex == itemCount) {
        return;
    }

    // Include the current item in the solution
    solution[currentIndex] = 1;
    containerLoader(weights, solution, itemCount, maxWeight, currentWeight + weights[currentIndex], currentIndex + 1, bestWeight);

    // Exclude the current item from the solution
    solution[currentIndex] = 0;
    containerLoader(weights, solution, itemCount, maxWeight, currentWeight, currentIndex + 1, bestWeight);
}

int main() {
    int itemCount, maxWeight;
    int weights[MAX_ITEMS], solution[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &itemCount);

    printf("Enter the weights of the items:\n");
    int i;
    for ( i = 0; i < itemCount; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the maximum weight capacity of the container: ");
    scanf("%d", &maxWeight);

    for ( i = 0; i < itemCount; i++) {
        solution[i] = 0;
    }

    int bestWeight = 0;
    containerLoader(weights, solution, itemCount, maxWeight, 0, 0, &bestWeight);

    printf("Maximum weight in the container: %d\n", bestWeight);

    return 0;
}

