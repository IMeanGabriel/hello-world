#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
bool vis[MAXN];
vector<int> g[MAXN];
int val[MAXN];
int nowmin=INF, cnt=0;
void dfs(int now, unordered_map<int, int> &mp) {
	for(const auto & x:g[now]) {
		if(vis[x]) continue;
		vis[x]=1;
		if(val[x]<nowmin) nowmin=val[x];
		if(mp.find(val[x])==mp.end()) {
			cnt++;
			mp[val[x]]=1;
		}
		dfs(x, mp);
	}
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m, ans=INF;
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		for(int i=1;i<=n;++i) scanf("%d", &val[i]);
		for(int i=0;i<m;++i) {
			int v, u, ru, rv;
			scanf("%d%d", &u, &v);
			g[u].push_back(v); g[v].push_back(u);
		}
		for(int i=1;i<=n;++i) {
			if(vis[i])continue;
			unordered_map<int, int> mp;
			nowmin=INF, cnt=0;
			dfs(i, mp);
			if(cnt+nowmin<ans) {
				ans=cnt+nowmin;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i) g[i].clear();
	}
	return 0;
}
// #include<cstdio> 
// #include<cstring>
// #include<algorithm>
// #include<vector>
// #define max_n 100010
// using namespace std;
// int pre[max_n];
// int n,s;
// vector<int> v[max_n]; //存图

// void dfs(int x){
//     int cnt=v[x].size();
//     for(int i=0;i<cnt;i++)
//     {
//         if(!pre[v[x][i]])
//         {
//             pre[v[x][i]]=x;
//             dfs(v[x][i]);
//         }
//     }
// }

// int main(){
//     int t,p1,p2;
//     scanf("%d",&t);
//     while(t--){
//         for(int i=0;i<=n;i++){
//             pre[i]=0;
//             v[i].clear();
//         }
//         scanf("%d %d",&n,&s);
//         for(int i=0;i<n-1;i++){
//             scanf("%d %d",&p1,&p2);
//             v[p1].push_back(p2); //无向图
//             v[p2].push_back(p1);
//         }
//         dfs(s);
//         pre[s]=-1;
//         for(int i=1;i<=n;i++){
//             if(i>1) printf(" ");
//             printf("%d",pre[i]);
//         }
//         printf("\n");
//     }
//     return 0;
// }