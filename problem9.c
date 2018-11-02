#include<stdio.h>
#include<math.h>

unsigned long long int isSpecial(int N){
    unsigned long long int a, b, c;
    unsigned long long int pdt = 0;
    for(a = 3; a <= (N-3)/3; a++){
        b = (N*N - 2*N*a)/(2*(N - a));
        c = (N-a-b);
        if((a*a + b*b == c*c)){
            if(a*b*c > pdt)
                pdt = a*b*c;
        }
    }
    return pdt;
}

/*
int main(){
    int a, b, c, N;
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int N;
        scanf("%d",&N);
        unsigned long long int num = isSpecial(N);
        if(num > 0)
            printf("%lld\n",num);
        else
            printf("%d\n", -1);
    }
    return 0;
}
*/

int main(){
    int N=1000;
    unsigned long long int num = isSpecial(N);
    if(num > 0)
        printf("%lld\n",num);
    else
        printf("%d\n", -1);
    return 0;
}

