#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000
unsigned int limit = ((LIMIT-1)/2)+1;
/*
void seive(char *primeArr){
    unsigned long long int i, j;
    for( i = 2; (i * i) < 2000003; i++)
        if(primeArr[i])
            for( j = 2 * i; j < 2000003; j+=i)
                primeArr[j] = 0;
}
*/

void seive(char *primeArr){
    unsigned long long int i, j;
    for(i = 1; ((2*i+1)*(2*i+1)) < LIMIT; i++){
        if(primeArr[i]){
            for(j = (2*i)*(i+1); j < limit; j+=(2*i+1))
                primeArr[j] = 0;
        }
    }
    
}

int main(){
    int testcase;
    scanf("%d", &testcase);
    char *primeArr;
  //printf("%d\n", limit);
    primeArr = (char*) malloc(sizeof(char)*limit);
    memset(primeArr, 1, limit);
    seive(primeArr);
  //for(int k = 1; k < limit; k++)
  //    if(primeArr[k])
  //         printf("%d ", 2*k+1);
  //          printf("\n");
    unsigned long long int *sum, i, j;
    sum = (unsigned long long int*) malloc(sizeof(unsigned long long int) * (LIMIT+1));
    if(!sum)
        printf("FAIL\n");
    sum[0] = 0;
    sum[1] = 0;
    sum[2] = 2;
    printf("Start\n");
    for(i = 3; i <=LIMIT ; i++){
        sum[i] = 2;
        for(j = 1; j <= (i-1)/2; j++){
            if(primeArr[j])
                sum[i] += (2*j+1);
        }
    }
    printf("Done\n");
  // for(i = 1; i < 12; i++)
  //     printf("%llu ", sum[i]);
  //     printf("\n");
    while(testcase--){
        unsigned long long int N;
        scanf("%llu", &N);
        printf("%llu\n", sum[N]);
    }
    return 0;
}
