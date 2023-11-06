#include <stdio.h>

int main(){
    int a[1000000];
    int b;
    int min = 1000001, max = -1000001;
    
    scanf("%d", &b);
    
    for(int i=0;i<b;i++){
        scanf("%d", &a[i]);
        if(min > a[i])
            min = a[i];
        if(max < a[i])
            max = a[i];
    }
    printf("%d %d", min, max);
}