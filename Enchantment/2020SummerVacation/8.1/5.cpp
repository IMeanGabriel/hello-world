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

struct node{
    int damage[MAXN];
    int delay[MAXN];
    int ed[MAXN];
    int hp[MAXN];
}weapon;

int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int l,r;
        double ans=0;
        scanf("%d%d",&l,&r);
        for(int i=l;i<=r;i++)
        {
            ans+=(double)1.0/i;
        }
        printf("%lf\n",(double)(r-l+1)/ans);
    }
    return 0;
}
