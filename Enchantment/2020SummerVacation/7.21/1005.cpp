#include <iostream>
#include <string.h>
#include <stdio.h>
 
using namespace std;
typedef long long LL;
const int N = 100005;
const LL MOD = 1000000009;
 
LL fac[N],A[N],B[N];
 
void Init()
{
    fac[0] = 1;
    for(int i=1; i<N; i++)
        fac[i] = fac[i-1] * i % MOD;
    A[0] = B[0] = 1;
    for(int i=1; i<N; i++)
    {
        A[i] = A[i-1] * 691504013 % MOD;
        B[i] = B[i-1] * 308495997 % MOD;
    }
}
 
LL quick_mod(LL a,LL b,LL MOD)
{
    LL ans = 1;
    a %= MOD;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % MOD;
            b--;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}
 
LL Solve(LL n,LL k)
{
    LL ans = 0;
    for(int r=0; r<=k; r++)
    {
        LL t = A[k-r] * B[r] % MOD;
        LL x = fac[k];
        LL y = fac[k-r] * fac[r] % MOD;
        LL c = x * quick_mod(y,MOD-2,MOD) % MOD;
        LL tmp = t * (quick_mod(t,n,MOD) - 1) % MOD * quick_mod(t-1,MOD-2,MOD) % MOD;
        if(t == 1) tmp = n % MOD;
        tmp = tmp * c % MOD;
        if(r & 1) ans -= tmp;
        else      ans += tmp;
        ans %= MOD;
    }
    LL m = quick_mod(383008016,MOD-2,MOD);
    ans = ans * quick_mod(m,k,MOD) % MOD;
    ans = (ans % MOD + MOD) % MOD;
    return ans;
}
 
int main()
{
    int T;
    LL n,k;
    Init();
    scanf("%d",&T);
    while(T--)
    {
        cin>>n>>k;
        cout<<Solve(n,k)<<endl;
    }
    return 0;
}


// #include <iostream>
// #include<cstring>
// #include<cstdio>
// #include<algorithm>
// #include<string>
// #include<map>
// const int maxn=1000000;
// const int mod=10000;
// #define me(a) memset(a,0,sizeof(a))
// #define ll long long
// #define int long long
// using namespace std;
// struct node{
//     int a[2][2];
//     node()
//     {
//         memset(a,0,sizeof(a));
//     }
// };

// long long  power(long long n, long long k)
// {
// 	if (k <= 0)
// 		return 1;
// 	else
// 		return n*power(n, k - 1);
// }
// node jx(node a,node b)
// {
//     node s;
//     for(int i=0;i<2;i++)
//         for(int j=0;j<2;j++)
//             for(int k=0;k<2;k++)
//                 s.a[i][k]=(s.a[i][k]+a.a[i][j]*b.a[j][k])%mod;
//     return s;
// }
// node qsort(node a,int n)
// {
//     node s;
//     for(int i=0;i<2;i++)
//         s.a[i][i]=1;
//     while(n)
//     {
//         if(n&1)
//             s=jx(s,a);
//         a=jx(a,a);
//         n>>=1;
//     }
//     return s;
// }
// int32_t main()
// {
//     node a;
//     long long n,c,k,w;
//     int t;
//     long long ans;
//     a.a[0][0]=a.a[1][0]=a.a[0][1]=1;
//     scanf("%lld",&t);
//     while(t--)
//     {
//         scanf("%lld%lld%lld",&n,&c,&k);
//         //cout<<n<<" "<<c<<" "<<k<<endl;
//         ans=0;
//         for(w=0;w<=n*c;w+=c)
//         {
//             node s=qsort(a,w);
//             ans+=power(s.a[1][0],k);
//             ans%=1000000009;
//         }
//         printf("%lld\n",ans);
//     }
//     return 0;
// }


// def fib3(n):
//     b = bin(n)
//     fn_prev = 1
//     fn = 0  # F[0] = 0
//     sign = 2
//     for i in b[2:]:
//         prev_sqr = fn_prev * fn_prev
//         fn_sqr = fn * fn
//         fn = 4 * fn_sqr - prev_sqr + sign  # F[2k+1] = 4*F[k]^2 - F[k-1]^2 + 2*(-1)^k
//         fn_prev = fn_sqr + prev_sqr  # F[2k-1] = F[k]^2 + F[k-1]^2
//         if i == '0':
//             fn = fn - fn_prev  # F[N] = F[2k] = F[2k+1] - F[2k-1], F[N-1] = F[2K]
//             sign = 2
//         else:
//             fn_prev = fn - fn_prev  # F[N] = F[2K+1], F[N-1] = F[2K]
//             sign = -2
//     return fn

// int main()
// {
// 	int n = 3;
// 	int k = 2;
// 	scanf("%d%d", &n, &k);
// 	int ret=power(n, k);
// 	printf("%d\n", fib3(2));
// 	system("pause");
// 	return 0;
// }