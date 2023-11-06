#include <stdio.h>

int main(){
    int a,b;
    int c[100];
    
    scanf("%d %d", &a, &b);
    
    for(int i=0;i<100;i++){
        c[i] = i+1;
    }
    
    for(int i=0;i<b;i++){
        int d,e;
        scanf("%d %d", &d, &e);
        
        int temp;
        temp = c[d-1];
        c[d-1] = c[e-1];
        c[e-1] = temp;
    }
    
    for(int i=0;i<a;i++){
        printf("%d ", c[i]);
    }
}