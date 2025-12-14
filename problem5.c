#include <stdio.h>

int main(){

int n,a[50];
printf("Enter size: ");
if(scanf("%d",&n)!=1 || n<=0){ printf("Invalid, please use only integer values!"); return 0; }
printf("Enter elements: ");

for(int i=0;i<n;i++) scanf("%d",&a[i]);
for(int i=0;i<n;i++)
for(int j=i+1;j<n;)
if(a[i]==a[j]){
for(int k=j;k<n-1;k++) a[k]=a[k+1];
n--;
} else j++;
printf("Array after removing duplicates: ");
for(int i=0;i<n;i++) printf("%d ",a[i]);

    return 0;
}
