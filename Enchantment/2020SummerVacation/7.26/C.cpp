#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
// #define long long int
bool vis[MAXN];
vector<int> g[MAXN];

long long mult(long long n)
{
    
    // int ans=0;
    // for(int i=1;i<=n;i++)
    // {
    //     ans+=i;
    // }
    // return ans;
    return (n+1)*n/2;

}

int main()
{
    long long k;
    scanf("%lld",&k);
    while(k--)
    {
        long long n,m;
        long long ans;
        scanf("%lld%lld",&n,&m);
        if(n==1||m==0)
            cout<<"0"<<endl;
        //cout<<mult(n-1)<<" "<<mult(n-2*m-1)<<endl;
        else
        {
            if(m<=(n/2))
            {
                ans=mult(n-1)-mult(n-2*m-1);
                cout<<ans<<endl;
                //cout<<1<<endl;
            }
            if(m>(n/2))
            {
                cout<<mult(n-1)<<endl;
                //cout<<2<<endl;
            }
            
        }
    }
    return 0;
}



// 9+8+7 6 5 4 3 2 
// -3+2+1
//     }
//     5 2 3 4 1
//     5 4 3 2 1
//     5 1:4+3=7
//     5 2:4+3+2+1=10

//     6 2 3 4 5 1
//     6 5 3 4 2 1

// 10 9 8 4 5 6 7 3 2 1


// \
//  \
//   \
//       /
//      /
//     /
//    /
//        \
//         \
//          \


//     6 1：5+4=9
//     6 2：n-1+n-2+(n-2-1)*