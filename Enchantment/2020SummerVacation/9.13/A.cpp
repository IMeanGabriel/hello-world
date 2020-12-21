// #include <iostream>
// #include<cstring>
// #include<cstdio>
// #include<algorithm>
// #include<string>
// #include<unordered_map>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;
// const int MAXN=1000005;
// const int INF=0x3f3f3f3f;
// // #define long long int

// struct node()
// {
//     int x;
//     int y;
// };


// int main()
// {
//     int n;
//     while(scanf("%d",&n)!=0)
//     {
//         node dot[MAXN];
//         int maxx=-MAXN,maxy=-MAXN,minx=MAXN,miny=MAXN;
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d%d",&dot[i].x,&dot[i].y);
//             if(dot[i].x>maxx)
//             {
//                 maxx=dot[i].x;
//                 index1=i;
//             }   
//             if(dot[i].x<minx)
//             {
//                 minx=dot[i].x;
//                 index2=i;
//             }   
//             if(dot[i].y>maxy)
//             {
//                 maxy=dot[i].y;
//                 index3=i;
//             }   
//             if(dot[i].y>miny)
//             {
//                 miny=dot[i].y;
//                 index4=i;
//             }  
//         }
         
//         for(int i=1;i<4;i++)
//         {
//             for(int j=i+1;j<=4;j++)
//             {
//                 double midx=(double)(dot[i].x+dot[j].x)/2;
//                 double midy=(double)(dot[i].y+dot[j].y)/2;
//                 double k=(double)0-(double)(dot[i].y-dot[j].y)/(dot[i].x-dot[j].x);
//                 double ansb=(double)(midy-midx*k);
//                 double ansx=(double)(0-ansb/k);
//             }
//             ans=max(ansx,ans);
//         }
//         }
//         double x=0.0;
//         double time=0.0;
        
//     }
// }


#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=5e4+5;

double x[MAXN], y[MAXN];
int main() {
	int n; while(~scanf("%d", &n) && n) {
		for(int i=0;i<n;++i) {
			scanf("%lf%lf", &x[i], &y[i]);
		}
		if(n==1) {
			printf("%lf %lf\n",x[0], y[0]);
			continue;
		}
		int cnt=0, ii=-1, jj=-1;
		double mx=-1.0;
		for(int i=0;i<n;++i) {
			for(int j=i+1;j<n;++j) {
				double tmp=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				if(tmp>mx) {
					ii=i, jj=j, mx=tmp;
				}
			}
		}
		sort(st, st+cnt, cmp);
		double xx=(x[ii]+x[jj])/2.0, yy=(y[ii]+y[jj])/2.0;
		double k=-(x[ii]-x[jj])/(y[ii]-y[jj]);
		double ans=xx-yy/k;
		printf("%lf %lf\n", ans, sqrt((ans-x[ii])*(ans-x[ii])+y[ii]*y[ii]));
	}
	return 0;
}