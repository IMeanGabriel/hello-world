// #include<bits/stdc++.h>
// using namespace std;

// struct node{
//     double x;
//     double y;
// }point[50006];

// int main()
// {
//     int T;
//     scanf("%d",&T);
//     while(T--)
//     {
//         int x,y,t;
//         scanf("%d%d%d",&x,&y,&t);
//         int ans=2*(t/y+(t/y==0?0:1))-1+t/(x-1)+(t/(x-1)==0?0:1);
//         printf("%d\n",ans);
//     }
// }


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
const double esp=1e-5;//精度控制在1e-5 -- 1e-10之间 否则 不是WA 就是TLE！！！试过
struct node{
double x,y;
}p[50001];
int n;
double dis(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y));
}
 
double solve(double pos)
{
    double maxx=-200000;
    node po;
    po.x=pos,po.y=0;
    for(int i=0;i<n;i++)
    {
        double tt=dis(po,p[i]);
        maxx=max(maxx,tt);
    }
    return maxx;
}
int main()
{
    double l,r,ml,mr;
    int i,j;
    while(scanf("%d",&n),n)
    {
        ml=200000;mr=-200000;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            if(ml>p[i].x) ml=p[i].x;
            if(mr<p[i].x) mr=p[i].x;
        }
        while((mr-ml)>esp)
        {
            double mid=(mr-ml)/3;
            l=ml+mid,r=ml+2*mid;
//            printf("%lf %lf\n",ml,mr);
//            printf("l=%lf   solve(l)=%lf  r=%lf   solve(r)=%lf\n",l,solve(l),r,solve(r));
            if(solve(l)>=solve(r))ml=l;
            else mr=r;
        }
        printf("%.9lf %.9lf\n",mr,solve(mr));
    }
    return 0;
}
