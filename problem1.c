/*Write a program to determine if the sum of three user-input integers is even or odd as well as if the
number is prime or composite. */
#include <stdio.h>
int main(){
    int a, b, c, sum;
    int prime = 1;
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3)
    {
        printf("Wrong input! Please enter integers only.");
        return 0;
    }
    sum = a + b + c;
    printf("Sum = %d\n", sum);
    printf("Sum is %s\n", (sum % 2 == 0) ? "Even" : "Odd");
    if (sum <= 1)
    {
        printf("Sum is neither Prime nor Composite");
        return 0;
    }
    for (int i = 2; i * i <= sum; i++)
    {
        if (sum % i == 0)
        {
            prime = 0;
            break;
        }
    }
    printf("Sum is %s", prime ? "Prime" : "Composite");
    return 0;
}
/*	Code Logic
Using scanf to ensure exactly three integers are entered by the user, rejecting invalid input.
Calculates the sum of the three integers.
Determines if the sum is even or odd and displays the result.
Checks if the sum is prime or composite
Treats sums less than or equal to 1 as neither prime nor composite.
Uses a loop up to the square root of the sum to check for divisibility.*/
