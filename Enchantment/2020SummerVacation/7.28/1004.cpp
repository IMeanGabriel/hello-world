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
// // #define long long int
// bool vis[MAXN];
// vector<int> g[MAXN];
// int a[MAXN];
// int b[MAXN];
// int main()
// {
//     int k;
//     scanf("%d",&k);
//     while(k--)
//     {
//         int n,p;
//         scanf("%d%d",&n,&p);

//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&a[i]);
//         }

//         int j=1;
//         for(int i=1;i<=n;i++)
//         {
//             if(a[i]%p==0&&a[i]!=0)
//             {
//                 b[j]=a[i];
//                 j++;
//             }
//             if(a[i]%p!=0&&a[i+1]%p!=0)
//             {
//                 a[i+1]+=a[i];
//                 printf("now a[%d]=%d\n",i+1,a[i+1]);
//             }
//         }
//         for(int i=1;i<j;i++)
//         {
//             printf("%d ",b[i]);
//         }
//         printf("%d\n",j-1);

        
//     }
//     return 0;
// }


#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int MAXN=100005;
const int INF=0x3f3f3f3f;
const int MOD=998244353;

int pre[MAXN], cnt[MAXN];

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        int n, p; scanf("%d%d", &n, &p);
        for(int i=1;i<=n;++i) {
            scanf("%d", &pre[i]);
            pre[i]=(pre[i]%p+pre[i-1])%p;
            
        }
        for(int i=1;i<=n;++i) {
            cnt[pre[i]]++;
        }
        int ans=0;
        for(int i=0;i<p;++i) {
            if(i && cnt[i]) cnt[i]--;
            ans=max(ans,cnt[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}