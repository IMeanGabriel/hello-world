#include<bits/stdc++.h>
using namespace std;
const int MOD=10000006;

inline int getpow(int a,int b)
{
    int ret=1;
    for(;b;b>>=1,a=a*a%MOD)
        if(b&1)
            ret=ret*a%MOD;
    return ret;
}

int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    cout<<getpow(x,n);
}