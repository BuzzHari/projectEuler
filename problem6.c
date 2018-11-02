#include<stdio.h>

/*int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int n;
        scanf("%d", &n);
        unsigned int a, b;
        a = (((n)*(n+1))/2)*(((n)*(n+1))/2);
        b = ((n)*(n+1)*(2*n+1))/6;
        printf("%u\n", a - b);
    }
    return 0;

}*/


int main(){
    int n=100;
    unsigned int a, b;
    a = (((n)*(n+1))/2)*(((n)*(n+1))/2);
    b = ((n)*(n+1)*(2*n+1))/6;
    printf("%u\n", a - b);
    return 0;

}
