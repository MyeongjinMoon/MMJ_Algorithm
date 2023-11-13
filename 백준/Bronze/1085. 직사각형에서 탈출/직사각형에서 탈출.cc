#include<stdio.h>

int main(){
    int a,b,c,d;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    int min = a;
    if(min > c-a)
        min=c-a;
    if(min > b)
        min = b;
    if(min > d-b)
        min = d-b;
    printf("%d", min);
}