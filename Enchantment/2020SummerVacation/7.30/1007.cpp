#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int INF=0x3f3f3f3f;
// #define long long int
bool vis[MAXN]={0};
vector<int> g[MAXN];
int axis[2*MAXN];

int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int n;
        int tmp;
        int x,y;
        memset(axis,0,sizeof(axis));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            tmp=y-x+MAXN;
            axis[tmp]++;
        }
        int cnt=0;
        for(int j=0;j<2*MAXN;j++)
        {
            if(axis[j]!=0)
                cnt++;
        }
        printf("%d\n",cnt);

    }
    return 0;
}
