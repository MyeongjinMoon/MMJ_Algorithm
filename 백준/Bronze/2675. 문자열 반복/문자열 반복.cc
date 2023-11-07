#include<stdio.h>
#include <string.h>

int main(){
    int a;
    
    scanf("%d", &a);
    
    for(int i=0;i<a;i++){
        int b;
        char c[20];
        scanf("%d %s", &b, c);
        
        for(int j=0;j<strlen(c);j++){
            for(int k=0;k<b;k++){
                printf("%c",c[j]);
            }
        }
        printf("\n");
    }
}