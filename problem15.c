#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MOD 1000000007

long long int mod_inverse(int i, long long int y){
    long long int x = 1, r = i;
    while(y){
        if(y % 2){
            x = x * r;
            x %= MOD;
        }
        r = r * r;
        r %= MOD;
        y /= 2;
    }
   return x;
}



int main() {
    long long int fact[1001];
    long long int ifact[501];
    fact[0] = 1;
    for(long long int i = 1; i <= 1000; i++)
        fact[i] = i * fact[i-1]%MOD;
    ifact[0] = 1;
    for(int i = 1; i <= 500; i++)
        ifact[i] = mod_inverse(i,MOD-2) * ifact[i-1] % MOD;
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        long long int ans = fact[n+m] * (ifact[n]*ifact[m]%MOD) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
