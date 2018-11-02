#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
#define SIZE 1000000000
#define TRUE 1
#define FALSE 0

int main(){
    char *arr;
    arr=(char*)malloc(sizeof(char)*SIZE);
    memset(arr,TRUE,SIZE);
    unsigned int i=2;
    for(i; i*i<=SIZE; i++){
        if(arr[i])
            for(unsigned int j=i*2;j<=SIZE; j+=i)
                arr[j]=FALSE;
    }

    int testcase=0;
    scanf("%d",&testcase);
    while(testcase--){
        unsigned long long num;
        scanf("%llu",&num);
        unsigned int max=0;
        for(unsigned int i=2; i<=num && i<=SIZE; i++){
            if(num%i==0 && arr[i])
                max=i;
        }
        printf("%u\n",max);
    }
    
    return 0;
}
*/

/*
int main(){
    int testcase=0;
    scanf("%d",&testcase);
    while(testcase--){
        unsigned long long int num;
        scanf("%llu",&num);
        unsigned long long int factor,last_factor;
        factor=2;
        if(num%2==0){
            last_factor=2;
            num=num/2;
            while(num % 2 == 0)
                num=num/2;
        }
        else
            last_factor=1;
        factor=3;
        while(num>1 && factor*factor<=num){
            if(num % factor == 0){
                last_factor=factor;
                num = num / factor;
                while( num % factor == 0)
                    num = num/factor;
            }
            factor+=2;
        }
        if(num == 1)
            printf("%llu\n",last_factor);
        else
            printf("%llu\n",num);
    }
    return 0;
}
*/

int main(){
    unsigned long long int num=600851475143;
    unsigned long long int factor,last_factor;
    factor=2;
    if(num%2==0){
        last_factor=2;
        num=num/2;
        while(num % 2 == 0)
            num=num/2;
    }
    else
        last_factor=1;
    factor=3;
    while(num>1 && factor*factor<=num){
        if(num % factor == 0){
            last_factor=factor;
            num = num / factor;
            while( num % factor == 0)
                num = num/factor;
        }
        factor+=2;
    }
    if(num == 1)
        printf("%llu\n",last_factor);
    else
        printf("%llu\n",num);
    return 0;
}
