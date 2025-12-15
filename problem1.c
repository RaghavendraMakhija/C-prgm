#include <stdio.h>

int main() {
    int a, b, c, sum;
    int prime = 1;

    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Wrong input! Please enter integers only.");
        return 0;
    }

    sum = a + b + c;
    printf("Sum = %d\n", sum);
    printf("Sum is %s\n", (sum % 2 == 0) ? "Even" : "Odd");

    if (sum <= 1) {
        printf("Sum is neither Prime nor Composite");
        return 0;
    }

    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
            prime = 0;
            break;
        }
    }

    printf("Sum is %s", prime ? "Prime" : "Composite");
    return 0;
}
