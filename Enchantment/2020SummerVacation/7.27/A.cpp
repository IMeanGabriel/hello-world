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
bool vis[MAXN];
vector<int> g[MAXN];

int seat1[MAXN];
int seat2[MAXN];


int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        double n;
        scanf("%lf",&n);
        double ans=2*((1+sqrt(2)+sqrt(3))*n)*((1+sqrt(2)+sqrt(3))*n);
        printf("%.5f\n",ans);
    }
    return 0;
}