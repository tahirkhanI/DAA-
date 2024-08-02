#include <stdio.h>
#define N 4

void print(int b[][N]) {
	int i,j;
    for ( i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf(" %d ", b[i][j]);
        printf("\n");
    }
}

int safe(int b[][N], int r, int c) {
	int i,j;
    for (i = 0; i < c; i++)
        if (b[r][i])
            return 0;
    for ( i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (b[i][j])
            return 0;
    for ( i = r, j = c; j >= 0 && i < N; i++, j--)
        if (b[i][j])
            return 0;
    return 1;
}

int solve(int b[][N], int c) {
	int i;
    if (c >= N)
        return 1;
    for (i = 0; i < N; i++) {
        if (safe(b, i, c)) {
            b[i][c] = 1;
            if (solve(b, c + 1))
                return 1;
            b[i][c] = 0;
        }
    }
    return 0;
}

int main() {
    int b[N][N] = {{0}};
    if (!solve(b, 0))
        printf("No solution\n");
    else
        print(b);
}
