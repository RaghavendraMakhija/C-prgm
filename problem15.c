/*Create a recursive function to find the nth term of the Fibonacci series. */
#include <stdio.h>

int fib(int n) { //Recursive function fib is used to calculate the nth Fibonacci term.
    if (n < 0) return -1; //Edge conditions in fib handle n < 0 (returns -1), n = 0 (returns 0), and n = 1
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
int main() {
    int n, result;
    printf("Enter n (n >= 0): ");
    if (scanf("%d", &n) != 1 || n < 0) { //By using scanf with input validation, the program ensures n is a non-negative integer.
        printf("Invalid input!");
        return 1;
    }
    result = fib(n);
    printf("Fibonacci term %d = %d\n", n, result);
    return 0;
}
