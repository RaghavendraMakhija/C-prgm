/*Take each element of the 4x4 matrix from the user and print it, then add each element from the 4x4
matrix and print the sum, print the sum of both the diagonals */
#include <stdio.h>
int main(){
    int a[4][4], sum = 0, d1 = 0, d2 = 0;
    printf("Enter 16 integers for 4x4 matrix:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
            { // scanf accepts 16 integer inputs from the user to fill a 4x4 matrix then stores the inputs in a 2D array.
                printf("Wrong input! Please enter integers only.");
                return 0;
            }
            sum += a[i][j];
            if (i == j)
                d1 += a[i][j];
            if (i + j == 3)
                d2 += a[i][j];
        }
    }
    printf("\nMatrix:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\nTotal Sum = %d", sum);             // Calculate the total sum of all matrix elements while reading the input.
    printf("\nMain Diagonal Sum = %d", d1);      // Calculates the sum of the main diagonal elements where row index equals column index.
    printf("\nSecondary Diagonal Sum = %d", d2); // Calculates the sum of the secondary diagonal elements where row index plus column index equals 3.
    return 0;
}
/*Code Logic:
Displays the matrix in a structured 4x4 format.
Prints the total sum, main diagonal sum, and secondary diagonal sum.*/
