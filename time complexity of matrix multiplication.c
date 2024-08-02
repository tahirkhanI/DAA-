#include <stdio.h>

void multiplyMatrices(int n, int a[][n], int b[][n], int c[][n], int *operations) {
	int i,j,k;
    for (i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            c[i][j] = 0;
            for ( k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                *operations += 2; 
            }
        }
    }
}

int main() {
    int n,i,j;

    printf("Enter the size of the matrices (n x n): ");
    scanf("%d", &n);

    int a[n][n], b[n][n], c[n][n];
    int operations = 0;

    printf("Enter elements of the first matrix:\n");
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of the second matrix:\n");
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    multiplyMatrices(n, a, b, c, &operations);

    printf("Resultant matrix:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("Total operations (multiplications + additions): %d\n", operations);

    return 0;
}

