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
        int n;
        int road,rank;
        int tail1=0,tail2=0;
        int head1=MAXN,head2=MAXN;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&road,&rank);
            if(road==1)
            {
                seat1[rank]=1;
                if(rank>tail1)
                    tail1=rank;
            }
            if(road==2)
            {
                seat2[rank]=1;
                if(rank>tail2)
                tail2=rank;
            }
        }
        int flg=0;
        for(int i=1;i<=tail2;i++)
        {
            if(seat2[i]==1)
            {
                if(seat1[i+1]==0&&i<tail1-1)
                    seat2[i]=0;
            }
        }
        int maxtail2=0;
        for(int i=1;i<=tail2;i++)
        {
            if(seat2[i]==1)
            {
                maxtail2=i;
                flg=1;
            }
        }
        if(flg==0)
            cout<<tail1+1<<endl;
        if(flg==1)
            cout<<max(maxtail2,tail1)+2<<endl;
        

    }
    return 0;
}