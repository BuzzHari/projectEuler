#include<stdio.h>
#define MAX (1000-1)


/*function to add the multiples of the number
    3+6+9+12+...+999=3(1+2+3...+333)
    similarly,
    5+10+15+....+995=5(1+2+3+...+199)
    and the last number is equal to MAX/num rounded down to nearest integer.
*/

int func(int num){
    int n=MAX/num;
    int res=(n*(n+1)*num)*(0.5);
    return res;
}

int main(){
    int sum_3=0,sum_5=0,sum_15=0;
    sum_3=func(3);
    sum_5=func(5);
    sum_15=func(15);
    printf("%d\n",sum_3+sum_5-sum_15);
    return 0;
}
