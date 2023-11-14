#include<stdio.h>

int main(){
    int a[3];
    
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    
    if(a[0]==a[1]&&a[1]==a[2]){
        printf("%d", a[0] + a[1] + a[2]);
        return 0;
    }
    else{
        int max=a[0], index=0, b=0;
        if(a[1] > max){
            max = a[1];
            index = 1;
        }
        if(a[2] > max){
            max = a[2];
            index = 2;
        }
        for(int i=0;i<3;i++){
            if(index==i)
                continue;
            b+=a[i];
        }
        if(max < b)
            printf("%d", a[0]+a[1] + a[2]);
        else{
            printf("%d", a[0]+a[1] + a[2] - (max - b + 1));
        }
    }
}