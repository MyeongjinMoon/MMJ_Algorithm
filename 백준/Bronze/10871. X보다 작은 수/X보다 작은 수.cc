#include <stdio.h>

int main(){
    int a,b;
    int n[10000];
    scanf("%d %d", &a, &b);
    
    for(int i=0;i<a;i++){
        scanf("%d", &n[i]);
        if(n[i]<b)
            printf("%d ",n[i]);
    }
}