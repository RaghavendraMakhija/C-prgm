/* Swap every two adjacent elements in an array using pointers */
#include <stdio.h>

int main(){
    int n, a[50], ch;
    int *p = a;
    printf("Enter number of elements (1-50): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 50)
    {
        printf("Invalid size!\n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        return 1;
    }
    printf("Enter %d integers:", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", p + i) != 1)
        {
            printf("Invalid input! Integers only.\n");

            while ((ch = getchar()) != '\n' && ch != EOF);
            return 1;
        }
    }
    printf("\nOriginal array:");
    for (int i = 0; i < n; i++)
        printf("%d ", *(p + i));
    for (int i = 0; i < n - 1; i += 2)
    {
        int temp = *(p + i);
        *(p + i) = *(p + i + 1);
        *(p + i + 1) = temp;
    }
    printf("\nArray after swapping:");
    for (int i = 0; i < n; i++)
        printf("%d ", *(p + i));
    return 0;
}
/*•	Code Logic
-	Use of scanf to accept the number of elements, rejecting invalid input and clearing the input buffer on error.
-	Reads n integers into an array using pointers, rejecting non-integer input.
-	Swaps every two adjacent elements in the array using pointer arithmetic.*/
