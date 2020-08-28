#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn=1e5+5;

struct DSU{
    int fa[maxn];
    int n;
    int num;
    void init(int n){
        this->n=n;
        num=0;
        for(int i=1;i<=n;++i)fa[i]=i;
    }
    int fand(int x){
        return x==fa[x]?x:fa[x]=fand(fa[x]);
    }
    void merge(int x,int y){
        int fx=fand(x);
        int fy=fand(y);
        if(fx!=fy){
            ++num;
            fa[fx]=fy;
        }
    }
    int get(){
        return num;
    }
}dsu;

int n,m;
vector<int> g[maxn];
map<int,vector<int>> mp;
int vis[maxn];
int a[maxn];
int ans;

void solve(){
    mp.clear();
    cin>>n>>m;
    for(int i=0;i<=n;++i)g[i].clear();
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=0;i<=n;++i)vis[i]=0;
    for(int i=1;i<=n;++i)mp[a[i]].push_back(i);
    mp[0].push_back(0);
    for(int i=1,a,b;i<=m;++i){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans=0;
    dsu.init(n);
    int m=mp.size();
    auto p=mp.rbegin();
    int sum=0;
    for(int i=1;i<m;++i){
        int hnow=p->first;
        for(auto x:p->second){
            vis[x]=1;
            ++sum;
        }
        for(auto u:p->second){
            for(auto v:g[u]){
                if(vis[v]){
                    dsu.merge(u,v);
                }
            }
        }
        int hnxt=(++p)->first;
        int dh=hnow-hnxt;
        ans+=dh*(sum-dsu.get());
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
}