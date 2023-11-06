#include <stdio.h>

int main(){
    int a, temp=0;
    scanf("%d", &a);
    
    for(int i=1; i<=a;i++){
        temp +=i;
    }
    printf("%d", temp);
}