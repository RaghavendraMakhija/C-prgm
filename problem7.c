#include <stdio.h>

int main() {
    int n, i;
    printf("Enter size: ");
    scanf("%d", &n);
    int a[n];
    int *p = a;

    printf("Enter elements: ");
    for(i = 0; i < n; i++) scanf("%d", p+i);

    int max1 = *p, max2 = -999999;

    for(i = 1; i < n; i++) {
        if(*(p+i) > max1) {
            max2 = max1;
            max1 = *(p+i);
        } else if(*(p+i) > max2 && *(p+i) != max1)
            max2 = *(p+i);
    }

    printf("Second largest = %d\n", max2);
    return 0;
}
