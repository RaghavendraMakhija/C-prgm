#include <stdio.h>

int main(){
    int a[4][4], sum=0, d1=0, d2=0;

    printf("Enter 16 integers for 4x4 matrix:\n");

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(scanf("%d",&a[i][j])!=1){
                printf("Wrong input! Please enter integers only.");
                return 0;
            }
            sum += a[i][j];
            if(i==j) d1 += a[i][j];
            if(i+j==3) d2 += a[i][j];
        }
    }

    printf("\nMatrix:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\nTotal Sum = %d", sum);
    printf("\nMain Diagonal Sum = %d", d1);
    printf("\nSecondary Diagonal Sum = %d", d2);

    return 0;
}
