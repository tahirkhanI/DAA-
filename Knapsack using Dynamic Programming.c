#include <stdio.h>

// Function to find the maximum value that can be accommodated in the knapsack
int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n+1][capacity+1];
    
    // Initialize the DP table with 0
    int i,w;
    for ( i = 0; i <= n; i++) {
        for ( w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i-1] <= w) {
                // Choose the maximum of including or excluding the item
                dp[i][w] = (values[i-1] + dp[i-1][w - weights[i-1]] > dp[i-1][w]) ? 
                            values[i-1] + dp[i-1][w - weights[i-1]] : dp[i-1][w];
            } else {
                // Exclude the item
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n,i,capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the weights and values of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d weight: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Item %d value: ", i + 1);
        scanf("%d", &values[i]);
    }

    int maxValue = knapsack(weights, values, n, capacity);
    printf("Maximum value in the knapsack: %d\n", maxValue);

    return 0;
}

