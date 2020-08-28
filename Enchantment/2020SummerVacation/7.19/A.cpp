#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int inf=0x3f3f3f3f;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        int n,m;
        int tmp=10006;
        scanf("%d%d",&n,&m);
        int a,b;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            int water=0,cal=0;

            while(water<m)
            {
                water+=a;
                cal+=b;
            }
            // cout<<"water"<<water<<" cal"<<cal<<endl;
            // cout<<"tmp"<<tmp<<endl;
            if(cal<tmp)
            {
                tmp=cal;
            }
            //cout<<"        now tmp="<<tmp<<endl;
        }
        cout<<tmp<<endl;
    }
}