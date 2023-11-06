#include <stdio.h>

int main(){
    int d[6] = {0};
    int a;
    for(int i =0;i<3;i++){
        scanf("%d", &a);
        d[a-1]++;
    }
    int max=0, flag;
    for(int i=5;i>=0;i--){
        if(d[i] > max){
            max=d[i];
            flag=i + 1;
        }
    }
    if(max == 3){
        printf("%d", 10000 + flag*1000);
    }
    else if(max ==2){
        printf("%d", 1000 + flag*100);
    }
    else{
        printf("%d", flag*100);
    }
}