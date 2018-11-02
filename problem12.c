#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100001
#define FIND_TRIANGLE_NUMBER(n) (1ULL*n*(n+1))>>1


int find_factor_count(char prime_arr[], unsigned long long int limit, unsigned long long int num){
    int total = 1;
    int count_factor = 0;
    unsigned long long int limt = num;
    for(unsigned long long int i = 2; i<= limit; i++){
        count_factor = 0;
        if(prime_arr[i]){
            if(num % i == 0){
                while(num % i == 0){
                    num /= i;
                    count_factor += 1;
                }
            total = total * (count_factor + 1);
            }
        }
    }
    return total;
}


void generate_prime_no(char prime_arr[], unsigned long long int limit){
    for(unsigned long long int i = 2; i*i <= limit; i++){
        if(prime_arr[i] == 1){
            for(unsigned long long int j=i*2; j<=limit; j+=i)
                prime_arr[j] = 0;
        }
    }
}

void increment_count_arr(unsigned long long int count_of_factors[], unsigned long long int number, int count, int *index){
        //printf("Count-%d, Index-%d, number-%llu\n", count, *index, number);
        while(count > *index && count_of_factors[*index] == 0){
            count_of_factors[*index] = number;
            (*index)++;
        }   
}

int main(){
    unsigned long long int *triangle_numbers;
    triangle_numbers = (unsigned long long int*) malloc(sizeof(unsigned long long)*MAX);
    unsigned long long int count_of_factors[1001] = {0};
    unsigned long long int limit = 10000;
    char *prime_arr;
    prime_arr = (char *) malloc(sizeof(char)*limit);
    memset(prime_arr, 1, limit);
    generate_prime_no(prime_arr, limit);
    int index = 1;
    for(unsigned long long int i = 2; i < MAX && index < 1001; i++){
        triangle_numbers[i] = FIND_TRIANGLE_NUMBER(i);
        int count = find_factor_count(prime_arr, limit, triangle_numbers[i]);
        increment_count_arr(count_of_factors, triangle_numbers[i], count, &index);
    }
    //for(int i = 1; i < 1001; i++){
    //    printf("%llu ", count_of_factors[i]);
    //}
    //printf("\n");
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%llu\n", count_of_factors[n]);
    }
    return 0;
}
