#include<stdio.h>

int main(){
    int  a;
    long long b=2;
    scanf("%d", &a);
    
    for(int i=0;i<a;i++){
        b = b*2 - 1;
    }
    
    printf("%lld", b*b);
}