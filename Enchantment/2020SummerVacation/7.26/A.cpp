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
        int k;
        int a;
        double b;
        double ans=0.0;
        double tmp;
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&a);
            scanf("%lf",&b);
            // cout<<a<<" "<<b<<endl;
            // cout<<(double)1.0-b<<endl;
            // cout<<(double)a+1.0-b<<endl;

            tmp=(double)((1.0-b)/(a+1.0-b));     
            ans=max(ans,tmp);      

        }
        //cout<<ans<<endl;
                  printf("%.5f\n",ans);   
    }

}