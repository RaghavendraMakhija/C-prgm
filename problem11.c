/*Implement Bubble sort or Selection sort on an array based on the input from the user and on the sorted
array perform binary search algorithm to find an element */
#include <stdio.h>
#include <string.h>
int readSingleInt(int *out) // Takes the size of the array using a safe line based input method to reject garbage input.
{
    char buf[128], extra;
    if (!fgets(buf, sizeof(buf), stdin))
        return 0;
    return sscanf(buf, " %d %c", out, &extra) == 1;
}
/*readSingleInt function reads one full line using fgets and then uses sscanf with an extra character check to ensure only
 a single integer is present and no garbage like letters or extra numbers are entered this prevents inputs like 10abc or 10 20*/
int readArray(int a[], int n)
{ /*readArray function reads the entire line of numbers at once and then parses exactly n integers from it using sscanf with %n 
    which ensures the user enters exactly n integers and nothing more or less lines*/
    char buf[256];
    int count = 0;
    char *ptr;

    if (!fgets(buf, sizeof(buf), stdin))
        return 0;
        ptr = buf;
    while (count < n)
    {
        int x, consumed;
        if (sscanf(ptr, " %d%n", &x, &consumed) != 1)
            return 0;
        a[count++] = x;
        ptr += consumed;
    }
    int extra;
    if (sscanf(ptr, " %d", &extra) == 1)
        return 0; //after reading n integers an extra sscanf check is done to detect any additional numbers 
        //which would mean invalid input edge condition handling lines
    return 1;
}
int main()
{
    int n, a[50], choice, key;
    printf("Enter size (1-50): ");
    if (!readSingleInt(&n) || n < 1 || n > 50)
    {
        printf("Invalid size!\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    if (!readArray(a, n))
    {
        printf("Invalid integer input!\n");
        return 1;
    }
    printf("\nChoose sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("Enter choice: ");
    if (!readSingleInt(&choice) || (choice != 1 && choice != 2))
    {
        printf("Invalid choice!\n");
        return 1;
    }
    if (choice == 1)
    {
        /* Bubble Sort */
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (a[j] > a[j + 1])
                {
                    int t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
                }
    }
                else
    {
        /* Selection Sort */
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[min])
                    min = j;
            int t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
    }
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nEnter key to search: ");
    if (!readSingleInt(&key))
    {
        printf("Invalid key!\n");
        return 1;
    }
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == key)
        {
            printf("Found\n");
            return 0;
        }
        else if (a[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    printf("Not Found\n");
    return 0;
}
/*How the sorting loops work:
For bubble sort:
The first for loop controls how many passes are required. Each pass places the next largest element at the end.
The inner for loop compares adjacent elements and swaps them if they are in the wrong order.
With each outer iteration, the effective range of the inner loop reduces because the largest elements are already settled.
For selection sort:
The first loop fixes the current index where the smallest remaining element should go.
The inner loop scans the unsorted part of the array to find the minimum element index.
After the inner loop ends, a single swap places the minimum element at its correct position.
This guarantees the left portion of the array remains sorted.*/
