#include<stdio.h>

int main(){
    int a[6] = {1, 1, 2, 2, 2, 8};
    int b[6];
    
    for(int i=0;i<6;i++){
        int c;
        scanf("%d", &c);
        printf("%d ",a[i]-c);
    }
}