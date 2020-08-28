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
    int a[MAXN];
    while(k--)
    {
        int n;
        int ma=0,mi=MAXN;
        int index1,index2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(ma<a[i])
            {
                ma=a[i];
                index1=i;
            }
            if(mi>a[i])
            {
                mi=a[i];
                index2=i;
            }
        }
        while(a[index2]-a[index1]!=1)
        {
            for(int i=1;i<=n;i++)
            {
                a[i]++;
                for(int i=1;i)
            }
        }
        
    return 0;
}
