#include<bits/stdc++.h>
using namespace std;
const int MAXN=100006;
#define ll long long

ll total;
ll factor[110];

ll mul(ll a,ll b,ll p)
{
    ll res=0;
    while(b!=0)
    {
        if(b&1)
            res=(res+a)%p;
            a=(a+a)%p;
            b>>=1;
    }
    return res;
}

ll pow(ll a,ll b,ll p)
{
    ll res=1;
    ll k=a;
    while(b)
    {
        if(b&1)
            res=mul(res,k,p)%p;
            k=mul(k,k,p)%p;
            b>>=1;
    }
    return res%p;
}

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

bool witness(ll a,ll n,ll x,ll sum)
{
    ll judge=pow(a,x,n);
    if(judge==n-1||judge==1)
        return 1;
    while(sum--)
    {
        judge=mul(judge,judge,n);
        if(judge==n-1)
            return 1;
    }
    return 0;
}

bool Miller_Rabin(ll n,int s)
{
    if(n<2)
        return 0;
    if(n==2)
        return 1;
    if((n&1)==0)
        return 0;
    ll x=n-1;
    ll sum=0;
    while(x%2==0)
    {
        x>>=1;
        sum++;
    }
    for(ll i=1;i<=s;i++)
    {
        ll a=rand()%(n-1)+1;
        if(!witness(a,n,x,sum))
            return 0;
    }
    return 1;
}

ll pollard(ll n,ll c)
{
    ll x,y,d,i=1,k=2;
    x=rand()%n;
    y=x;
    while(1)
    {
        i++;
        x=(mul(x,x,n)+c)%n;
        d=gcd(y-x,n);
        if(d<0)
            d=-d;
        if(d>1&&d<n)
            return d;
        if(y==x)
            return n;
        if(i==k)
        {
            y=x;
            k<<=1;
        }
    }
}

void find(ll n)
{
    if(Miller_Rabin(n,5))
    {
        factor[++total]=n;
        return ;
    }
    ll p=n;
    while(p>=n)
    {
        p=pollard(p,rand()%(n-1)+1);
    }
    find(n/p);
    find(p);
}

int main()
{

    int T;
    scanf("%lld",&T);
    while(T--)
    {
        ll q,n,m,i,t,;
        scanf("%lld",&t);

    }

}