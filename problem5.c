/* Create a program to remove all duplicates from an array of integers */

#include <stdio.h>

int main(){
    int n, a[50];
    char buf[256], extra;
    printf("Enter size (1-50): ");
    if (!fgets(buf, sizeof(buf), stdin) ||
        sscanf(buf, " %d %c", &n, &extra) != 1 ||
        n <= 0 || n > 50)
    {
        printf("Invalid size!\n");
        return 1;
    }
    printf("Enter %d integers (in one line):", n);
    if (!fgets(buf, sizeof(buf), stdin))
    {
        printf("Invalid input!");
        return 1;
    }
    int count = 0, consumed;
    char *ptr = buf;
    while (count < n)
    {
        if (sscanf(ptr, " %d%n", &a[count], &consumed) != 1)
        {
            printf("Invalid input! Enter exactly %d integers.", n);
            return 1;
        }
        ptr += consumed;
        count++;
    }
    if (sscanf(ptr, " %c", &extra) == 1)
    {
        printf("Invalid input! Enter exactly %d integers.", n);
        return 1;
    }
    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n;)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < n - 1; k++)
                  a[k] = a[k + 1];
                n--;
            }
            else j++;
        }
    }
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
/*•	Code Logic
 -	Uses fgets and sscanf to ensure a valid array size (1-50) is entered, rejecting invalid input.
 -	Accepts exactly n integers from the user in one line, validating each entry and rejecting extra or non-integer inputs.
 -	Stores the integers in an array and prints the original array.
 -	Removes duplicate values by comparing each element with the subsequent elements and shifting the array left when duplicates are found.*/
