#include<stdio.h>

int main(){
    int a,b, temp=0;
    int n[101];
    scanf("%d", &a);
    
    for(int i=0;i<a;i++){
        scanf("%d", &n[i]);
    }
    scanf("%d", &b);
    for(int i=0;i<a;i++){
        if(n[i] == b){
            temp++;
        }
    }
    printf("%d", temp);
}