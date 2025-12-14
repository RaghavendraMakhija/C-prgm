#include <stdio.h>

int main(){
    int n, a[50];
    printf("Enter size (1-50): ");
    if(scanf("%d",&n)!=1 || n<=0 || n>50)
    {
        printf("Invalid size! Enter an integer between 1 and 50.");
        return 0;
    }

    printf("Enter %d integers:", n);
    for(int i=0;i<n;i++)
    {
        if(scanf("%d",&a[i])!=1){
            printf("Wrong input! Only integers allowed.");
            return 0; }
    }

    for(int i=0;i<n-1;i+=2)
    {
        int t=a[i];
        a[i]=a[i+1];
        a[i+1]=t;
    }

    printf("Result: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
