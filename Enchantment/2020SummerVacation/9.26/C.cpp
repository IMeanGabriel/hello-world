// #include <iostream>
// #include<cstring>
// #include<cstdio>
// #include<algorithm>
// #include<string>
// #include<unordered_map>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;
// const int MAXN=1000005;
// const int INF=0x3f3f3f3f;
// const int MOD=2147493647;
// // #define int long long


// int main()
// {
//     int T;
//     scanf("%d",&T);
//     while(T--)
//     {
//         long long n,a,b;
//         scanf("%lld%lld%lld",&n,&a,&b);
//         long long temp;
//         for(long long i=3;i<=n;i++)
//         {
//             temp=(a*2+b+(((i*i)%MOD*i)*MOD*i)%MOD)%MOD;
//             a=b;
//             b=temp;
//         }
//         printf("%lld\n",temp);
//     }
// }


struct Mat
{
    LL m[101][101];
};//存储结构体
Mat a,e; //a是输入的矩阵，e是输出的矩阵
Mat Mul(Mat x,Mat y)
{
    Mat c;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            c.m[i][j] = 0;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                c.m[i][j] = c.m[i][j]%mod + x.m[i][k]*y.m[k][j]%mod;
            }
        }
    }
    return c;
}
Mat pow(Mat x,LL y)//矩阵快速幂
{
    Mat ans = e;
    while(y){
        if(y&1) ans = Mul(ans,x);
        x = Mul(x,x);
        y>>=1;
    }
    return ans;
}



#include<bits/stdc++.h>
///#define mod 2147493647
using namespace std;
typedef long long ll;
const ll mod=2147493647UL;
struct matrix
{
    ll m[10][10];
};
matrix mutil(matrix a,matrix b)
{
    matrix c;
    memset(c.m,0,sizeof(c.m));
    for(int i=1;i<=7;i++)
    {
        for(int j=1;j<=7;j++)
        {
            for(int k=1;k<=7;k++)
            {
                c.m[i][j]+=(a.m[i][k]%mod*b.m[k][j]%mod)%mod;
            }
            c.m[i][j]%=mod;
        }
    }
    return c;
}
matrix power(matrix A,ll k)
{
    matrix ans;
    for(int i=1;i<=7;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(i==j)
            ans.m[i][j]=1;
            else
                ans.m[i][j]=0;
        }
    }
    while(k)
    {
        if(k&1)
        {
            ans=mutil(ans,A);
            k--;
        }
        k>>=1;
        A=mutil(A,A);
    }
    return ans;
}
int main()
{
    ll n,i,j,t;
    ll a,b,res;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&a,&b);
        if(n==1)
            printf("%lld\n",a);
        else if(n==2)
            printf("%lld\n",b);
        else
        {
            matrix A;
            for(i=1;i<=7;i++)
            {
                for(j=1;j<=7;j++)
                {
                  A.m[i][j]=0;
                }
            }
            A.m[1][1]=1;A.m[1][2]=2;A.m[1][3]=1;
            A.m[2][1]=1;
            A.m[3][3]=1;A.m[3][4]=4;A.m[3][5]=6;A.m[3][6]=4;A.m[3][7]=1;
            A.m[4][4]=1;A.m[4][5]=3;A.m[4][6]=3;A.m[4][7]=1;
            A.m[5][5]=1;A.m[5][6]=2;A.m[5][7]=1;
            A.m[6][6]=1;A.m[6][7]=1;
            A.m[7][7]=1;
            matrix ans=power(A,n-2);
            res=0;
            res=(res+ans.m[1][1]%mod*b%mod)%mod;
            res=(res+ans.m[1][2]*a%mod)%mod;
            res=(res+ans.m[1][3]*81%mod)%mod;
            res=(res+ans.m[1][4]*27%mod)%mod;
            res=(res+ans.m[1][5]*9%mod)%mod;
            res=(res+ans.m[1][6]*3%mod)%mod;
            res=(res+ans.m[1][7]%mod)%mod
            ///res=(((ans.m[1][1]%mod*b%mod)%mod+(ans.m[1][2]*a)%mod)%mod+(ans.m[1][3]*81)%mod+(ans.m[1][4]*27)%mod+(ans.m[1][5]*9)%mod+(ans.m[1][6]*3)%mod+ans.m[1][7])%mod;
            printf("%lld\n",res);
        }
    }
}