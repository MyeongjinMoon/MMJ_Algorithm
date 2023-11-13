#include<stdio.h>

int main(){
    int a[3][2];
    for(int i=0;i<3;i++){
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    for(int i=0;i<2;i++){
        int b[1001]={0};
        for(int j=0;j<3;j++){
            b[a[j][i]]++;
        }
        for(int j=1;j<1001;j++){
            if(b[j] == 1){
                printf("%d ", j);
                break;
            }
        }
    }
}