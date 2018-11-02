#include<stdio.h>

int main(){
    unsigned long long int c=9999999999999999999U/2;
    unsigned long long int d=9999999999999999999U*0.5;
    unsigned long long int e=9999999999999999999U>>1;
    printf("%llu\n%llu\n%llu\n",c,d,e);
    printf("%lu\n",sizeof(size_t));
    char arr[]={2,4,5,6};
    int sum=255;
    for(int i=0; i<4; i++)
        sum+=arr[i];
    printf("%d\n", sum);
    char *str = "Hello"
                "World";
    printf("%c\n", str[5]);

    return 0;
}
