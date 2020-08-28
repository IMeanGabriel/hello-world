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


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int a[MAXN];
        int ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            //printf("%d ",a[i]);
        }
        for(int i=2;i<=n;i++)
        {
            if(a[i]<a[i-1])
            {

                ans=max(ans,a[i-1]-a[i]);
                a[i]=a[i-1];
                //printf("%d ",ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
// 3
// 4
// 5 3 2 5
// 5
// 1 2 3 5 3
// 3
// 1 1 1