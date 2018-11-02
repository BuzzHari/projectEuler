#include<stdio.h>
#include<stdlib.h>
#define MAX 40000000000000000
#define SIZE 10000000
/*
int main(){
    unsigned long long int *num;
    num = (unsigned long long int*)malloc(sizeof(unsigned long long int)*SIZE);
    if(!num){
        printf("ERROR\n");
        exit(0);
    }
        
    num[0]=1;
    num[1]=2;
    for(unsigned long long int i=2; i<SIZE; i++)
        num[i]=num[i-1]+num[i-2];
    int test_case;
  //  for(int i=0; i<MAX; i++)
  //      printf("%u ",num[i]);
    scanf("%d",&test_case);
    while(test_case--){
        unsigned long long int limit;
        scanf("%llu",&limit);
        unsigned long long int sum=0;
        for(unsigned long long int i=0; num[i]<=limit; i++)
            if(num[i]%2==0)
                sum+=num[i];
        printf("%llu\n",sum);
    }
    return 0;
}
*/

int main(){
    unsigned long long int *num;
    num = (unsigned long long int*)malloc(sizeof(unsigned long long int)*SIZE);
    if(!num){
        printf("ERROR\n");
        exit(0);
    }
        
    num[0]=1;
    num[1]=2;
    for(unsigned long long int i=2; i<SIZE; i++)
        num[i]=num[i-1]+num[i-2];
    unsigned long long int limit=4000000;
    unsigned long long int sum=0;
    for(unsigned long long int i=0; num[i]<=limit; i++)
        if(num[i]%2==0)
            sum+=num[i];
    printf("%llu\n",sum);
    return 0;
}
