/*Write a program to find the second-largest element in an array using pointers. */
#include <stdio.h>

int main(){
    int n, a[50], *p = a;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1 || n < 2)
    {
        printf("Invalid! please input only integers!");
        return 0;
    }
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", p + i);
    int max = *p, sec = -2147483648;
    for (int i = 1; i < n; i++)
    {
        if (*(p + i) > max)
        {
            sec = max;
            max = *(p + i);
        }
        else if (*(p + i) < max && *(p + i) > sec) 
            sec = *(p + i);
    }
    printf("Second Largest = %d", sec);
    return 0;
}
/*•	Code Logic
-	Using scanf to accept the size of the array, requiring at least 2 elements, rejecting invalid input.
-	Reads n integers into an array using pointers.
-	Initializes the largest (max) and second largest (sec) values.
-	Iterates through the array using pointers to update max and sec according to the values.*/
