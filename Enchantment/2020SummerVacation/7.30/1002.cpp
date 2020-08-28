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
        int n;
        scanf("%d",&n);
        double ans=0;
        int tmp=MAXN;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&weapon.damage[i],&weapon.delay[i]);
            weapon.ed[i]=0;
            weapon.hp[i]=0;
            for(int j=1;weapon.hp[i]<100;j++)
            {
                weapon.hp[i]+=weapon.damage[i];
                weapon.ed[i]+=weapon.delay[i];
            }
            //printf("%d\n",weapon.ed[i]);
            tmp=min(weapon.ed[i],tmp);
        }
        int cnt=0;
        for(int i=1;i<=MAXN;i++)
        {
            if(weapon.ed[i]==tmp)
                cnt++;
        }
        ans=1.0-(double)1.0*cnt/n*0.5;
        printf("%lf\n",ans);
    }
    return 0;
}
