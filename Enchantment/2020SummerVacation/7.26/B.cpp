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
bool vis[MAXN];
vector<int> g[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        double a;
        scanf("%lf",&a);
        if(a>1.0)
            printf("No\n");
        if(a>0.0&&a<=1.0)
            printf("Yes\n");
    }
}