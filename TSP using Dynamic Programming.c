#include <stdio.h>
#include <limits.h>
#define N 4
int tsp(int graph[N][N]) {
    int i, j, n = N;
    int VISITED_ALL = (1 << n) - 1;
    int dp[1 << N][N];
    for (i = 0; i < (1 << n); i++) {
        for ( j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    int tspUtil(int mask, int pos) {
        if (mask == VISITED_ALL) {
            return graph[pos][0];
        }

        if (dp[mask][pos] != -1) {
            return dp[mask][pos];
        }

        int ans = INT_MAX;
		int city;
        for ( city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int newAns = graph[pos][city] + tspUtil(mask | (1 << city), city);
                ans = (ans < newAns) ? ans : newAns;
            }
        }

        dp[mask][pos] = ans;
        return ans;
    }

    return tspUtil(1, 0);
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    printf("The minimum cost to visit all cities is %d\n", tsp(graph));
    return 0;
}

