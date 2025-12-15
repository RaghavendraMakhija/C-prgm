#include <stdio.h>

int main() {
    int r, c;
    int a[10][10], rot[10][10];
    /* Read matrix size */
    printf("Enter rows and columns: ");
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0 || r > 10 || c > 10) {
        printf("Invalid size! Enter positive integers (max 10).\n");
        return 1;
    }
    /* Read matrix elements */
    printf("Enter %d integers:\n", r * c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Wrong input! Integers only.\n");
                return 1;
            }
        }
    }
    /* Print original matrix */
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    /* Rotate 90° clockwise and Print rotated matrix */
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rot[j][r - 1 - i] = a[i][j];
        }
    }
    printf("\nRotated Matrix (90 degrees Clockwise):\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            printf("%d ", rot[i][j]);
        printf("\n");
    }
    return 0;
}
