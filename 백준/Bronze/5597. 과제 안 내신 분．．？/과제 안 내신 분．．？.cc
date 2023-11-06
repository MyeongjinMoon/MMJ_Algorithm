#include <stdio.h>

int main(){
    int a[30] = {0};
    
    for(int i=0;i<30;i++){
        int b;
        scanf("%d", &b);
        a[b-1]++;
    }
    for(int i=0;i<30;i++){
        if(a[i] == 0)
            printf("%d\n", i+1);
    }
}