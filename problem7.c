#include <stdio.h>

int main(){
    int n,a[50],*p=a;
        printf("Enter size: ");
            if(scanf("%d",&n)!=1 || n<2){
        printf("Invalid! please input only integers!"); return 0; 
        }
        else printf("enter elements:");            
            for(int i=0;i<n;i++) scanf("%d",p+i);
        int max=*p, sec=-2147483648;
            for(int i=1;i<n;i++){
        if(*(p+i)>max){
            sec=max; max=*(p+i);
        }
        else if(*(p+i)<max && *(p+i)>sec) sec=*(p+i);
        }
        if (scanf("%d",&n)!=1 || n<2)
                    {
                        printf("Invalid! please input only integers!"); return 0;
                    }
        printf("Second Largest = %d", sec);
    return 0;
}
