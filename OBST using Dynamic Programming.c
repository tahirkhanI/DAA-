#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j) {
    int k, s = 0;
    for ( k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalBST(int keys[], int freq[], int n) {
	int i,l,r;
    int cost[n][n];

    for ( i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for ( l = 2; l <= n; l++) {
        for ( i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            cost[i][j] = INT_MAX;

            for ( r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + 
                        ((r < j) ? cost[r + 1][j] : 0) + 
                        sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n,i;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];
    printf("Enter the keys:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    printf("Cost of Optimal BST is %d\n", optimalBST(keys, freq, n));
    return 0;
}
