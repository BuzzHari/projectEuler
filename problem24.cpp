#include<iostream>
#include<vector>
using namespace std;

int fact(int n){
    return (n==1||n==0)?1:fact(n-1)*n;
}

int main(){
    unsigned int number=0;
    vector<int> arr={0,1,2,3,4,5,6,7,8,9};
    int temp,remain=1000000-1,n=10;
    for(int i=1;i<9;i++){
        int temp=remain/fact(n-i);
        number=number*10+arr[temp];
        remain%=fact(n-i);
        arr.erase(arr.begin()+temp);
        if(remain==0)
            break;
    }
    for(int i=arr.size()-1; i>=0;i--)
        number=number*10+arr[i];
    printf("%u\n",number);
}
