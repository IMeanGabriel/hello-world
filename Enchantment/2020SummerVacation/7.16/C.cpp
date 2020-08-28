#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
 
int n, res;
double X, Y, R;
 
struct Point {
    
  double x, y;
} p[N];
 
map<pair<double, double>, int> mp;
 
bool solve(Point a, Point b, Point c)  //三点共圆圆心公式
{
  if (2 * (a.y - c.y) * (a.x - b.x) - 2 * (a.y - b.y) * (a.x - c.x) == 0 &&
      2 * (a.y - b.y) * (a.x - c.x) - 2 * (a.y - c.y) * (a.x - b.x) == 0)
    return false;
 
  X = ((a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y) * (a.y - c.y) -
       (a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y) * (a.y - b.y)) /
      (2 * (a.y - c.y) * (a.x - b.x) - 2 * (a.y - b.y) * (a.x - c.x));
  Y = ((a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y) * (a.x - c.x) -
       (a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y) * (a.x - b.x)) /
      (2 * (a.y - b.y) * (a.x - c.x) - 2 * (a.y - c.y) * (a.x - b.x));
  R = sqrt((X - a.x) * (X - a.x) + (Y - a.y) * (Y - a.y));
 
  return true;
}
 
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  Point o = {0, 0};
  for (int i = 1; i < n; i++) {
    mp.clear();
    for (int j = i + 1; j <= n; j++) {
      if (solve(o, p[i], p[j])) {
        auto now = make_pair(X, Y);
        res = max(res, ++mp[now]);
      }
    }
  }
  printf("%d\n", ++res);
  return 0;
}







// #include <bits/stdc++.h>
// #define N 200100
// #define ll long long
// using namespace std;
 
// int n,fa[N],head[N],deg[N],dfn[N],tot=0,cnt=0;
// bool isLeaf[N];
 
// struct edge
// {
//     int to,next;
// }e[N<<2];
 
// struct ans
// {
//     int ind,dfn;
// }q[N];
 
// bool cmp(ans a,ans b)
// {
//     return a.dfn<b.dfn;
// }
 
// void addedge(int u,int v)
// {
//     e[++tot].to=v;e[tot].next=head[u];head[u]=tot;
//     e[++tot].to=u;e[tot].next=head[v];head[v]=tot;
// }
 
// void dfs(int u)
// {
//     dfn[u]=++cnt;
//     for (int i=head[u];i;i=e[i].next)
//     {
//         if (e[i].to!=fa[u])
//         {
//             fa[e[i].to]=u;
//             dfs(e[i].to);
//         }
//     }
// }
 
// int main()
// {
//     int u,v,root,leaf=0;
//     cin>>n;
//     for (int i=1;i<n;i++)
//     {
//         scanf("%d%d",&u,&v);
//         deg[u]++;deg[v]++;
//         addedge(u,v);
//     }
//     for (int i=1;i<=n;i++)
//         if (deg[i]==1)
//         {
//             leaf++;
//             isLeaf[i]=1;
//         }
//         else root=i;
//     if (leaf%2==1)
//     {
//         isLeaf[n+1]=1;
//         addedge(root,n+1);
//     }
//     fa[root]=root;
//     dfs(root);
//     int num=0;
//     for (int i=1;i<=n+leaf%2;i++)
//     {
//         if (isLeaf[i])
//         {
//             q[++num].ind=i;
//             q[num].dfn=dfn[i];
//         }
//     }
//     sort(q+1,q+1+num,cmp);
//     cout<<(leaf+1)/2<<endl;
//     for (int i=1;i<=(leaf+1)/2;i++)
//     {
//         u=q[i].ind,v=q[i+(leaf+1)/2].ind;
//         if (u==n+1) u=root;
//         if (v==n+1) v=root;
//         cout<<u<<" "<<v<<endl;
//     }
//     return 0;
// }





