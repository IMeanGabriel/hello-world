#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int MAXN=500;

struct ITEM {
	int a, b, c, d;
};

int id[51];
bool vis[51];

vector<ITEM> obj[51];
int cnt; long long ans;
void dfs(int deep, int a, int b, int c, int d) {
	if(deep==cnt) {
		long long tmp=(100+a)*(100+b)*(100+c)*(100+d);
		if(tmp>ans) {
			ans=tmp;
		}
		return;
	}
	for(auto & x : obj[id[deep]]) {
		dfs(deep+1, a+x.a, b+x.b, c+x.c, d+x.d);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0;t<T;++t) {
		memset(vis, 0, sizeof(vis));
		int n, k;
		cnt=0; ans=100000000;
		scanf("%d%d", &n, &k);
		for(int i=0;i<n;++i) {
			scanf("%d",&t);
			if(!vis[t]) {
				id[cnt++]=t;
				vis[t]=1;
			}
			ITEM tmp;
			scanf("%d%d%d%d",&tmp.a,&tmp.b,&tmp.c,&tmp.d);
			obj[t].push_back(tmp);
		}
		dfs(0, 0, 0, 0, 0);
		printf("%lld\n",ans);
		for(int i=0;i<cnt;++i) obj[i].clear();
	}
	return 0;
}