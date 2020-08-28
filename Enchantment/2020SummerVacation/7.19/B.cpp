#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int inf=0x3f3f3f3f;

int t,x;
int u[]={0,60,62,65,67,70,75,80,85,90,95};
int v[]={0,10,17,20,23,27,30,37,40,43};

void solve()
{
    int ans=0;
    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=10;j++)
        {
            for(int k=0;k<=10;k++)
            {
                for(int t=0;t<=10;t++)
                {
                    if(u[i]+u[j]+u[k]+u[t]<=x)
                    {
                        ans=max(ans,v[i]+v[j]+v[k]+v[t]);
                    }
                }
            }
        }
    }
    cout<<ans/10<<"."<<ans%10<<endl;
}

int main()
{
    cin>>t;
    while(t--)
    {
        scanf("%d",&x);
        solve();
    }
}

// double judge(int n)
// {
//     if(n>=0&&n<=59)
//         return 0.0;
//     if(n>=60&&n<=61)
//         return 1.0;
//     if(n>=62&&n<=64)
//         return 1.7;
//     if(n>=65&&n<=66)
//         return 2.0;
//     if(n>=67&&n<=69)
//         return 2.3;
//     if(n>=70&&n<=74)
//         return 2.7;
//     if(n>=75&&n<=79)
//         return 3.0;
//     if(n>=80&&n<=84)
//         return 3.3;
//     if(n>=85&&n<=89)
//         return 3.7;
//     if(n>=90&&n<=94)
//         return 4.0;
//     if(n>=95&&n<=100)
//         return 4.3;
//     else return 0.0;
// }

// int main()
// {
//     int t;
// 	cin>>t;
    
// 	while(t--)
// 	{
//         int score;
//         scanf("%d",&score);
//         cout<<score<<endl;
//         double ans;
//         if(score>=0&&score<=95)
//         {
//             ans=judge(score);
//         }
//         if(score>95&&score<=190)
//         {
//             ans=max(judge(score/2)*2,4.3+judge(score-95));
//         }
//         if(score>190&&score<=285)
//         {
//             ans=max(judge(score/3)*3,4.3*2+judge(score-190));
//         }
//         if(score>285&&score<=380)
//         {
//             ans=max(judge(score/4)*4,4.3*3+judge(score-285));
//         }
//         if(score>380&&score<=400)
//         {
//             ans=17.2;
//             //cout<<ans<<endl;
//         }
//         // int full=score/95;
//         // //cout<<full<<endl;
//         // int res=score%95;
//         // //cout<<res<<endl;
//         // double ans1=(double)full*4.3+judge(res);
//         // int full2=score/85;
//         // int res2=score%85;
//         // double ans2=
//         printf("%.1f\n",ans);
//     }
// }
// 330
// 12.9+0
// 12.0+1.0

// 345
// 12.9+1.0

// 280
// 10.8
// 8.6+3.3



// 0-1
// 155  5.3

// 330
// 4 13.2
// 3 12.9

// 300
// 4 12
// 3 12.9


// 240
// 3 9.9
// 2 8.6

// 270
// 3 12
// 2 11.3

// 210
// 3 8.1
// 2 8.6


// 370

// 3.7+12.9 
// 16


// 95

// 190
// 285

// 345
// 4：345/4=86.
// 3：95*3+60
// 2：

// 95 /67 67

// 95 95/


// 95 190 285 380

// 95 95 60

