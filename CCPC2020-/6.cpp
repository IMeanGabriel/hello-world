#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>

using namespace std;

const int MAXN=3e5+5;

vector<int> g[MAXN];
bool vis[MAXN];

int bfs(int s) {
	set<pair<int, int> > st;
	int ans=0, cnt=0;
	queue<int> qu; qu.push(s);
	while(!qu.empty()) {	
		++cnt;
		int u=qu.front(); qu.pop();
		int len=g[u].size();
		for(int i=0;i<len;++i) {
			if(!st.count(make_pair(min(u, g[u][i]), max(u, g[u][i])))) {
				++ans;
				st.insert(make_pair(min(u, g[u][i]), max(u, g[u][i])));
			}
			if(!vis[g[u][i]]) {
				qu.push(g[u][i]);
				vis[g[u][i]]=1;
			}
		}
	}
	return ans-cnt;
}
int main() {
	int T; scanf("%d", &T);
	for(int kase=1;kase<=T;++kase) {
		int n, m; scanf("%d%d", &n, &m);
		for(int i=1;i<=n;++i) g[i].clear(), vis[i]=0;
		for(int i=0;i<m;++i) {
			int a, b; scanf("%d%d", &a, &b);
			g[a].push_back(b); g[b].push_back(a);
		}
		int ans=0;
		for(int i=1;i<=n;++i) {
			if(!vis[i]) {
				vis[i]=1;
				int tmp=bfs(i);
				if(tmp>0) ans+=tmp;
			}
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
} 
