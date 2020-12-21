#include<bits/stdc++.h>
using namespace std;
const int MOD=10000006;
#define ll long long

void exgcd(ll a,ll b,ll &x,ll &y,ll &c)
{
    if(!b)
    {
        y=0;
        x=1;
        c=a;
        return;
    }
    exgcd(b,a%b,y,x,c);
    y-=a/b*x;
}

int main()
{
    ll a,x,b,y,c;
    scanf("%lld%lld%lld%lld%lld",&a,&x,&b,&y,&c);
    exgcd(a,b,x,y,c);
}