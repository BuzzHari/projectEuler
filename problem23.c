#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int abundant_arr[30000];

unsigned long int findFactors(int num) {

    unsigned long int sum = 1;
    for (int i = 2; (i*i) <= num; ++i) {
        if (num % i == 0) {
            //printf("Factor: %d, %d\n", i, num/i);
            sum += i;
            if (i != num/i)
                sum += num/i;
        }
    }
    return sum;
}

int isAbundant(int i) {
    unsigned long int factorSum = 0;
    factorSum = findFactors(i);
    if (factorSum > i)
        return 1;
    return 0;
}

int main() {

    time_t startime, endtime; 

    startime = clock();
    for (int i = 1; i <= 28123; ++i) {
        if (isAbundant(i))
            abundant_arr[i] = 1;
    }

    unsigned long int sum = 0;
    const int smallest_abundant_number = 12;
    const int smallest_abundant_sum = 24;
    char abundant_sum_flag = 0;
    for (int i = 1; i <= 28123; ++i) {
        abundant_sum_flag = 0;
        if (i < smallest_abundant_sum) {
            sum +=i;
        }
        else {
            for (int j = smallest_abundant_number; j < i; ++j) {
                int temp = i - j;
                if (abundant_arr[j] && abundant_arr[temp]) {
                    abundant_sum_flag = 1;
                    break;
                }
            }
            if (!abundant_sum_flag) {
                sum += i;
            }
        } 
    }
    endtime = clock();
    int t = endtime - startime;
    printf("Sum: %lu\n", sum);
    printf("Time taken: %d ms\n", t / 1000);
    return 0;
}

