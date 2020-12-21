#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=1e5+5;
const int INF=0x3f3f3f3f;

long long na[MAXN], nb[MAXN], ma[MAXN], mb[MAXN];
bool vis[MAXN];
struct M {
	long long a, b;
}mm[MAXN];
bool cmp(M x, M y) {
	if(x.a!=y.a) return x.a<y.a;
	else return x.b>y.b;
}
int main() {
	int T; scanf("%d", &T);
	for(int kase=1;kase<=T;++kase) {
		memset(vis, 0, sizeof(vis));
		int n, m; scanf("%d%d", &n, &m);
		for(int i=0;i<n;++i) {
			scanf("%lld%lld", &na[i], &nb[i]);
		}
		for(int i=0;i<m;++i) {
			scanf("%lld%lld", &mm[i].a, &mm[i].b);
		}
		sort(mm, mm+m, cmp);
		for(int i=0;i<m;++i) ma[i]=mm[i].a, mb[i]=mm[i].b;
		bool flag=false;
		long long e=0ll;
		int cnt=0, i=0;
		while(i<n) {
			if(e>=na[i]) {
				e+=nb[i];
				++cnt;
				++i;
			} else {
				if(m==0) {
					flag=true;
					break;
				}		
				while(e<na[i]) {
					int id=lower_bound(ma, ma+m, e)-ma;
					int choose=-1; long long mx=-INF;
					for(int j=id;j>-1;--j) {
						if(ma[j]<=e && !vis[j]) {
							if(mb[j]>mx) {
								mx=mb[j];
								choose=j;
							}
						}
					}
					if(choose!=-1) {
						e+=mb[choose];
						vis[choose]=1;
						++cnt;
					} else {
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
		}
		if(flag) cnt=-1;
		printf("Case #%d: %d\n", kase, cnt);
	}
	return 0;
}
