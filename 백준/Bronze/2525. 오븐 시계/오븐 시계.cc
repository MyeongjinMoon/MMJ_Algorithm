#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    
    int h,m;
    h = c/60;
    m = c%60;
    
    m +=b;
    if(m>59){
        h++;
        m %= 60;
    }
    h +=a;
    if(h>23){
        h %= 24;
    }

    printf("%d %d", h, m);
}