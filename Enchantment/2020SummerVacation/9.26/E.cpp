
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN=1e2+5;
const int INF=0x3f3f3f3f;

int g[MAXN][MAXN];
bool vis[MAXN];
int ans, n, m, s;

void dfs(int u, bool choose, int tot, vector<int> &v) {
    //printf("%d\n", tot);
    if(u>n) return;
    if(v.size()==s) {
        for(int i=0;i<s;++i) {
            for(int j=i+1;j<s;++j) {
                //printf("i:%d j:%d\n", i, j);
                if(!g[v[i]][v[j]]) return;
            }
                
        }
        ++ans;
        return;
    }
    if(v.size()<s) {
        v.push_back(u+1);
        dfs(u+1, 1, tot+1, v);
        v.pop_back();
    }
    dfs(u+1, 0, tot, v);
}
int main() {
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--) {
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d", &n, &m, &s);
        for(int i=0,u,v;i<m;++i) {
            scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = 1;
        }
        ans = 0;
        vector<int> v; v.clear();
        dfs(0, 0, 0, v);
        printf("%d\n", ans);
    }
}
