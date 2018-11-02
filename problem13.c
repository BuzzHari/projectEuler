#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 54


void big_sum(char num_arr[], char sum_arr[]){
    int carryover = 0;
    int i = 49;
    int sum = 0;
    for(int index = 53; index >=0 ; index--){
        if(i >= 0)
            sum = (sum_arr[index]) + (num_arr[i--]-'0') + carryover;
        else
            sum = (sum_arr[index] + carryover); 
        carryover = sum / 10;
        //printf("sum: %d  carry: %d\n", sum, carryover);
        if(carryover)
            sum_arr[index] = sum % 10; 
        else
            sum_arr[index] = sum;
    }
}



int main(){
    char sum_arr[MAX];
    memset(sum_arr, 0, MAX);
    int n;
    scanf("%d", &n);
    while(n--){
        char num_arr[50];
        scanf("%s",num_arr);
        big_sum(num_arr, sum_arr);
    }
    int count = 0;
    for(int i = 0; i < 54; i++){
        if(sum_arr[i] == 0 && count == 0)
            continue;
        if(count < 10){
            printf("%d", sum_arr[i]);
            count++;
        }
    }
    return 0;
}

