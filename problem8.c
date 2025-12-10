#include <stdio.h>

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    for(int i = 0; i < n - 1; i += 2) {
        int *p = &a[i];
        int *q = &a[i+1];
        int temp = *p;
        *p = *q;
        *q = temp;
    }

    printf("After swapping: ");
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
