#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    printf("Enter n (n >= 0): ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Fibonacci term %d = %d\n", n, fib(n));
    return 0;
}
