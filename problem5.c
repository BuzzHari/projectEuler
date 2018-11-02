#include<stdio.h>
#include<math.h>

/*
#define MAX 40

int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        //int num;
        //scanf("%d", &num);
        for(unsigned long long int i = 1;; i++){
            int flag = 1;
            for(int j=1; j<=MAX && flag; j++){
                if(i % j == 0)
                    continue;
                else{
                    flag = 0;
                    break;
                }
            }

            if( flag == 1){
                printf("%llu\n", i);
                break;
            }
        }
    }
    return 0;
}
*/


int main(){
    int testcase;
    scanf("%d", &testcase);
    int p[13]={0,2,3,5,7,11,13,17,19,23,29,31,37};
    while(testcase--){
        int num;
        scanf("%d", &num);
        int a=1;
        unsigned long long N=1;
        int i=1;
        while(p[i] <= num){
            if (p[i]*p[i] > num)
                a=1;
            else
                a=(log(num)/log(p[i]));
            N = N * pow(p[i],a);
            i++;
        }

        printf("%llu\n",N);
    }
}

