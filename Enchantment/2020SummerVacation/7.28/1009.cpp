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

int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        string a,b;
        cin>>a;
        queue q1;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='(')
                cntl++;
            if(a[i]==')')
                cntr++;
            if(a[i]=='*')
                cnts++;
        }
        for(int i=0;i<a.length();i++)
        {
            
        }
        
    }
    return 0;
}
        // string a,b;
        // cin>>a;
        // int cntl=0,cntr=0,cnts=0;

        // //printf("%d %d %d\n",cntl,cntr,cnts);
        // while(cntl>0&&cntr>0)
        // {
        //     for(int i=0;i<a.length();i++)
        //     {
        //         if(a[i]=='(')
        //         {
        //             for(int j=i;j<a.length();j++)
        //             {
        //                 if(a[j]==')')
        //                 {
                            
        //                     cntl--;
        //                     cntr--;
        //                     continue;
        //                 }
        //             }
        //         }
        //     }
        // }
        // cout<<a<<endl;