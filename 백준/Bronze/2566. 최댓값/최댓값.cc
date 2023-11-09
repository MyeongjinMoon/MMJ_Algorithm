#include<stdio.h>

int main(){
    int a[9][9];
    
    int max=-1, b,c;
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] > max){
                max = a[i][j];
                b=i;
                c=j;
            }
        }
    }
    
    printf("%d\n%d %d", max, b+1,c+1);
}