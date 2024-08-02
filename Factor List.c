#include <stdio.h>

// Recursive function to find all factors of n
void findFactors(int n, int i) {
    if (i > n) {
        return;
    }
    if (n % i == 0) {
        printf("%d ", i);
    }
    findFactors(n, i + 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factors of %d are: ", n);
    findFactors(n, 1);

    return 0;
}

