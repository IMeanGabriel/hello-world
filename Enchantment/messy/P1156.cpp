#include<bits/stdc++.h>
using namespace std;
const int mod=9973;

int n,k;
struct M{
    int number[12][12];
};
M Mul(M a,M b)
{
    M c;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            c.number[i][j]=0;
            for(int k=0;k<n;k++)
                c.number[i][j]=(c.number[i][j]+a.number[i][k]*b.number[k][j]%mod)%mod;
            c.number[i][j]%=mod;
        }
    return c;
}

M Pow(M a,M b,int x)
{
    while(x)
    {
        if(x&1)
        {
            b=Mul(b,a);
        }
        x/=2;
        a=Mul(a,a);
    }
    return b;
}

int main()
{
    int t;
    M standard,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&standard.number[i][j]);
                tmp.number[i][j]=standard.number[i][j];
            }
        M res=Pow(standard,tmp,k-1);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=(ans+res.number[i][i])%mod;
        printf("%d\n",ans%mod);
    }
    return 0;
}