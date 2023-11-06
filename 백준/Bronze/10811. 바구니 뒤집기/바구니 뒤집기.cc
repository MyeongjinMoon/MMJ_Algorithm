#include <stdio.h>

int main(){
    int a,b;
    int c[100];
    
    scanf("%d %d", &a, &b);
    
    for(int i=0;i<a;i++){
        c[i] = i+1;
    }
    
    for(int i=0;i<b;i++){
        int d,e,temp;
        scanf("%d %d", &d, &e);
        
        
        for(int j=0;j<=(e-d)/2;j++){
            temp = c[e-1 - j];
            c[e-1 - j] = c[d-1 + j];
            c[d-1 + j] = temp;
        }
    }
    for(int i=0;i<a;i++){
        printf("%d ", c[i]);
    }
}