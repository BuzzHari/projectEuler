#include<stdio.h>
#include<string.h>
#define MAX (999*999)

int isPalindrome(int num){
    int realNum=num;
    int rev_num=0;
    while(num > 0){
        int lastDigit = num % 10;
        rev_num =(rev_num*10) + lastDigit;
        num /= 10;
    }

    if(realNum == rev_num)
        return 1;
    else
        return 0;
}

int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        // int num;
        // scanf("%d", &num);
        int maxPali=0;
        for(int i = 100; i < 1000; i++)
            for(int j=i; j < 1000; j++){
                if(isPalindrome(i * j) && (i * j) <= MAX)
                    if(i*j > maxPali)
                        maxPali = i * j;
            }
        printf("%d\n", maxPali);
    }

    return 0;    
}
