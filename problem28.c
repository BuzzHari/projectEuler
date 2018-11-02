#include<stdio.h>

int main(){
    int sum=1;
    int t=1;
    int inc_val;
    int i=1; 
    int n,num=1;
    while(t<=500){
        n=1;
        inc_val=2*i;
        while(n<=4){
            sum+=(inc_val+num);
            num+=inc_val;
            n++;
        }
        i++;
        t++;
    }
    printf("%d\n",sum);
    return 0;
}
