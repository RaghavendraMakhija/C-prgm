/*Write a C program to print equilateral triangle or Pyramid star pattern series of n rows using. For eg n=5. */
#include <stdio.h>

int main(){
    int n;
    printf("Enter number of rows: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }
    for (int i = 1; i <= n; i++)
    { // for loop runs i from 1 to n rows being printed
        for (int space = 1; space <= n - i; space++) // loop prints spaces before stars, runs n-i times creates left alignment for pyramid shape
            printf(" ");
        for (int star = 1; star <= i; star++) // loop prints stars runs i times each iteration prints "* " this increases stars per row
            printf("* ");
            printf("\n");
    }
    return 0;
}
/*code logic extended
outer loop increases i each iteration so rows grow from 1 star row to n star row
space loop decreases spaces as i increases shifting stars toward center
star loop increases stars as i increases forming pyramid shape*/
