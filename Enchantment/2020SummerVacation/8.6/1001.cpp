// #include<bits/stdc++.h>
// using namespace std;
// const int maxn=1e5+9;

// int a[maxn],b[maxn];

// int main()
// {
// 	int T;
//     scanf("%d",&T);
//     while(T--)
//     {
//         int n,l,r;
//         double ans=0.0;
//         scanf("%d",&n);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
//         //scanf("%d%d",&l,&r);
//         for(int i=1;i<=n;i++)
//         {
//             a[i]+=a[i-1];
//         }
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=i;j<=n;j++)
//             {
//                 ans+=(double)((a[j]-a[i-1])/(j-i+1));
//                 //printf("%lf\n",ans);
//             }
//         }
//         printf("%lf\n",ans);
//     }
// }

#include<stdio.h>
#define N 100010
const long long MOD =1000000007;
long long num1[4*N],s[4*N];

long long Qpow(long long a, long long n)//Qpow(Q,MOD-2)
{
    long long ans = 1;
    while(n) {
        if(n&1)
            ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        n>>=1ll;
    }
    return ans%MOD;//return Q^(-1)
}

int main()
{
	long long i,j;
	for(i=1;i<N;i++)
	num1[i]=Qpow(i,MOD-2);
	
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&s[i]);
			s[i]=(s[i]%MOD+s[i-1]%MOD)%MOD;
		}
		
		long long ans=0;
		for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		ans+=(((s[j]%MOD-s[i-1]%MOD+MOD)%MOD)*(num1[j-i+1]%MOD))%MOD, ans%=MOD;
		
        //printf("%lld\n",Qpow((1+n)*n/2,MOD-2)%MOD);
		ans=(ans*Qpow((1+n)*n/2,MOD-2))%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}