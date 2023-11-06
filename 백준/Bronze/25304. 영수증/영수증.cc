#include<stdio.h>

int main(){
    int a, n, temp=0;
    scanf("%d %d", &a, &n);
    
    for(int i=0;i<n;i++){
        int b,c;
        scanf("%d %d", &b, &c);
        temp += b*c;
    }
    if(temp==a)
        printf("Yes");
    else
        printf("No");
}