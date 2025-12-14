#include <stdio.h>

int main(){
    int sec,a,b,c=1;
    
    printf("Enter seconds: ");
    if(scanf("%d", &sec)!=1 || sec<0 ){
        printf("Invalid input! Enter positive integer.");
        return 0; 
    if (scanf("%d", &a,&b,&c)!=1)
    {
      printf("Invalid input! Enter positive integer.");
      return 0;
    }
    
    }
 
    printf("%d:%d:%d", sec/3600, (sec%3600)/60, sec%60);
    
    return 0;
}
