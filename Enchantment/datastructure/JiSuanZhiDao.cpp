#include<bits/stdc++.h>
using namespace std;
const int MAXN=20006;

int prime[MAXN];
bool vis[MAXN];
bool isPrime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
	    if(n%i==0 ) return false;
	}
        return true;
} 


// void getPrime(int n)
// {
//     memset(vis,0,sizeof(vis));
//     memset(prime,0,sizeof(prime));
//     prime[0]=0;
//     for(int i=2;i<=n;i++){
//         if(!vis[i])
//             prime[++prime[0]]=i;
//         for(int j=1;j<=prime[0]&&i<=n/prime[j];j++){
//             vis[i*prime[j]]=true;
//             if(i%prime[j]==0)
//                 break;
//         }
//     }
// }


int main()
{
    int n,m;
    int a[MAXN];
    scanf("%d%d",&n,&m);
    for(int j=1;j<=n;j++){
        scanf("%d",&a[j]);
    }
    //getPrime(n);
    int ans=MAXN;
    // for(int i=1;i<=20;i++)
    // {
    //     cout<<prime[i]<<" ";
    // }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(isPrime(a[i]+a[j]))
                ans=min(ans,a[i]+a[j]);
        }
    }
    cout<<ans<<endl;
}