#include <stdio.h>

int main() {
    float units, bill = 0;

    printf("Enter units consumed: ");
    if (scanf("%f", &units) != 1 || units < 0) {
        printf("Invalid input!\n");
        return 1;
    }

    if (units <= 100)
        bill = units * 5;
    else if (units <= 300)
        bill = 100 * 5 + (units - 100) * 8;
    else
        bill = 100 * 5 + 200 * 8 + (units - 300) * 10;

    printf("Total Bill = rupees %.2f only.\n", bill);
    return 0;
}
