#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 5000001
#define ODD(n) 1ULL*(3*n)+1
#define EVEN(n) 1ULL*n>>1


 long long int find_no_steps(long long int i,long long int *step_count){
       if(i == 1){ 
           return (*step_count)--;
       }
       else if(i % 2){
            i = ODD(i);
            (*step_count)++;
            return find_no_steps(i, step_count);
       }
       else{
           i = EVEN(i);
           (*step_count)++;
           return find_no_steps(i, step_count);
       }
}


void populate_collatz_arr(long long int collatz_arr[MAX]){
    long long int prev_longest = 0;
    long long int prev_num = 1;
    long long int step_count = 1;
    for(long long int i = 1 ; i < MAX; i++){
        step_count = 1;
        find_no_steps(i, &step_count);
        if(step_count >= prev_longest){
            prev_longest = step_count;
            prev_num = i;
        }
        collatz_arr[i] = prev_num;
    }
}



int main() {
    long long int *collatz_arr;
    collatz_arr = (long long int*) malloc(sizeof(long long int)*MAX);
    memset(collatz_arr, 0, MAX);
    populate_collatz_arr(collatz_arr);
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%lld\n", collatz_arr[n]);
    }
    return 0;
}

