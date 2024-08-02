#include <stdio.h>
int numDigits(int n) {
    if (n == 0) return 0;
    return 1 + numDigits(n / 10);
}

int reverseNumber(int n, int digits) {
    if (n == 0) return 0;
    return (n % 10) * pow(10, digits - 1) + reverseNumber(n / 10, digits - 1);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int digits = numDigits(number);
    int reversed = reverseNumber(number, digits);

    printf("Reversed number: %d\n", reversed);
    return 0;
}

