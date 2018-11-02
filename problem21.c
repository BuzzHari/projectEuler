#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int fact_arr[1000001];
int amicable_arr[1000001];


int sumOfFactors(int num){
    int sum = 1;
    for(int i = 2; i <= num/2; i++){
        if(num%i == 0)
            sum+=i;
    }
    return sum;
}

int isAmicableNumber(int num){
    int fact_num1 = fact_arr[num];
    int fact_num2 = fact_arr[fact_num1];
    
    if(num == fact_num1)
        return 0;
    if(fact_num2 == num)
        return 1;
    
    return 0;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    for(int i = 0; i < 200000; i++){
        printf("Finding sumOfFactors for: %d\n", i);
        fact_arr[i] = sumOfFactors(i);
    }
   
   // for(int i = 0; i < 10001; i++){
       // printf("%d %d\n", i, fact_arr[i]);
   //}
    
    int amicableSum = 0;
    
    for(int i = 0; i < 100001; i++){
        printf("Finding sumOfAmicableNumber for: %d\n", i);
        if(isAmicableNumber(i))
          amicableSum += i;
        
        amicable_arr[i] = amicableSum;       
    }
    printf("Calculations Done.\n"); 
    
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("FINAL SUM: %d\n", amicable_arr[n]);
    }
    return 0;
}

