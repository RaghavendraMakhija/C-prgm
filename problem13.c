#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {

        /* Print leading spaces */
        for (int space = 1; space <= n - i; space++)
            printf(" ");

        /* Print stars */
        for (int star = 1; star <= i; star++)
            printf("* ");

        printf("\n");
    }

    return 0;
}

