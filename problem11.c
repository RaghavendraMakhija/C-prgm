#include <stdio.h>

int main()
{
    int n, a[50], key;

    printf("Enter size (1-50): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50)
    {
        printf("Invalid size!");
        return 1;
    }

    printf("Enter %d integers:", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Wrong input! Integers only.");
            return 1;
        }
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }

    printf("Enter key to search: ");
    if (scanf("%d", &key) != 1)
    {
        printf("Invalid key!");
        return 1;
    }

    // Binary Search
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == key)
        {
            printf("Found");
            return 0;
        }
        else if (a[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }

    printf("Not Found");
    return 0;
}
