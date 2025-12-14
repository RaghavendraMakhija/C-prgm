#include <stdio.h>

int main(){
    int n, a[10][10];

    printf("Enter matrix size (1-10): ");
    if(scanf("%d",&n)!=1 || n<=0 || n>10){
        printf("Invalid size!");
        return 1;
    }

    printf("Enter %d integers:\n", n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(scanf("%d",&a[i][j])!=1){
                printf("Wrong input! Integers only.");
                return 1;
            }
        }
    }

    printf("\nRotated Matrix (90° Clockwise):\n");
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--)
            printf("%d ", a[j][i]);
        printf("\n");
    }

    return 0;
}
