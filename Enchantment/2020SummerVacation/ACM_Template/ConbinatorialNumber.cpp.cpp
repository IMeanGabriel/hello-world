#include<bits/stdc++.h>
using namespace std;
const int MOD=10000006;
#define ll long long

int fac[MAXN],inv[MAXN],facinv[MAXN];

void getinv(int n){
    fac[0]=1;
    for(int i=1;i<n;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
    inv[1]=1;
    for(int i=2;)
}