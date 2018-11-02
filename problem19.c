#include<stdio.h>


int ifLeapYear(int year){
    if(year%4==0 || (year%4==0&&(year%100==0&&year%400==0)))
            return 1;
    return 0;            
}
int main(){
    
    int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int count=0, day=5;
    for(int year=1901;year<=2000;year++){
        for(int i=0; i<12; i++){
            if(i==0)
                day=((months[11]%7)+day)%7;
            else{
                if(ifLeapYear(year))
                    months[1]=29;
                else
                    months[1]=28;
                day=((months[i-1]%7)+day)%7;
            }
            if(day==6)
                count+=1;
        }
    }
    printf("%d\n",count);
}

