#include<stdio.h>

int main(){
    char a[101];
    int count=0, b;
    scanf("%d",&b);
    scanf("%s", a);
    
    while(b>0){
        count += a[--b]-48;
    }
    printf("%d", count);
}