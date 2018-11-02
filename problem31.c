#include<stdio.h>
/*
int main(){
    int count=0;
    for(int i=0;i<=200;i++)
        for(int j=0;j<=100;j++)
            for(int k=0;k<=40;k++)
                for(int l=0;l<=20;l++)
                    for(int m=0;m<=10;m++)
                        for(int n=0;n<=4;n++)
                            for(int o=0;o<=2;o++)
                                for(int p=0;p<=1;p++)
                                    if(i+2*j+5*k+10*l+20*m+50*n+100*o+200*p==200)
                                        count+=1;
    printf("%d\n",count);
                                    
}
*/
int main(){
    int coins[]={1,2,5,10,20,50,100,200};
    int ways[201]={0};
    ways[0]=1;
    for(int i=0;i<8;i++)
        for(int j=coins[i];j<=200;j++){
            ways[j]+=ways[j-coins[i]];
        }
    printf("%d\n",ways[200]);
    return 0;
}
