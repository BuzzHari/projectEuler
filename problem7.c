#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000

void sieve(char *prime_arr){
    
    for(unsigned long long int i = 2; i * i < MAX; i++)
        if(prime_arr[i])
            for(unsigned long long int j = i * 2; j <= MAX; j+=i)
                prime_arr[j] = 0;
}


int main(){
    int testcase;
    scanf("%d", &testcase);
    char *prime_arr;
    prime_arr = (char*)malloc(MAX);
    memset(prime_arr, 1, MAX);
    sieve(prime_arr);
    while(testcase--){
        int num;
        scanf("%d", &num);
        int count = 0;
        for(unsigned long long int i = 2; i < MAX; i++)
            if(prime_arr[i]){
                count+=1;
                if(count == num){
                    printf("%llu\n", i);
                    return 0;
                    }
            }
            
    }
    return 0;
}
