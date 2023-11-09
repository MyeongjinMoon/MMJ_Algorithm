#include<stdio.h>

int main(){
    int n;
    int b[4] = {25, 10, 5, 1};
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        for(int i=0;i<4;i++){
            printf("%d ", a/b[i]);
            a%=b[i];
        }
        printf("\n");
    }
}