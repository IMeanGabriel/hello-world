#include<bits/stdc++.h>
using namespace std;

#define int long long

//DS
const int N=10005,M=100005,inf=1e18+7;
struct edge{int to,next,weight,cost;}e[M*2];
int tail[N],cnt=0;
void add_edge(int from,int to,int w,int c){
    e[cnt].to=to;
    e[cnt].weight=w;    //weight is capacity
    e[cnt].cost=c;      //cost is the cost per unit of flow
    e[cnt].next=tail[from];
    tail[from]=cnt;
    ++cnt;
}
void add_flow(int from,int to,int c){
    add_edge(from,to,1,c);
    add_edge(to,from,0,-c);
}

//GLOBAL param.
int n,m,s,t;
int ansflow,anscost;

//SPFA
int pre[N],flow[N],track[N],dis[N],vis[N];
int spfa(){
    for(int i=0;i<=t;++i)pre[i]=0,vis[i]=0,dis[i]=inf;
    flow[s]=inf,pre[s]=s,vis[s]=1,dis[s]=0;
    queue<int> q;q.push(s);
    while(!q.empty()){
        int cur=q.front();q.pop();vis[cur]=0;
        for(int i=tail[cur];~i;i=e[i].next){
            int nx=e[i].to;
            int w=e[i].weight;
            int c=e[i].cost;
            if(w>0&&dis[nx]>dis[cur]+c){
                dis[nx]=dis[cur]+c;
                pre[nx]=cur;
                flow[nx]=min(w,flow[cur]);
                track[nx]=i;
                if(!vis[nx]){
                    vis[nx]=1;
                    q.push(nx);
                }
            }
        }
    }
    return dis[t]!=inf;
}

//MCMF
void mcmf(){
    ansflow=0,anscost=0;
    while(spfa()){
        ansflow+=flow[t];
        anscost+=flow[t]*dis[t];
        int x=t;
        while(x!=s){
            e[track[x]].weight-=flow[t];
            e[track[x]^1].weight+=flow[t];
            x=pre[x];
        }
        cout<<anscost;
        if(ansflow<n)cout<<" ";
        else cout<<"\n";
    }
}

int a[55],b[55],c[55];
unordered_map<int,int> mp;
void solve(){
    cin>>n>>m;
    mp.clear();
    for(int i=1;i<=n;++i)cin>>a[i]>>b[i]>>c[i];
    int len=min(m,n+10);
    t=n*(len+1)+1;
    s=0;
    for(int i=s;i<=t;++i)tail[i]=-1;
    cnt=0;
    int tot=n;
    for(int i=1;i<=n;++i)add_flow(s,i,0);
    for(int i=1;i<=n;++i){
        int ctr=b[i]/(-2*a[i]);
        int lft,rgt;
        lft=ctr-len/2-4;
        rgt=lft+len-1;
        if(lft<1){
            rgt+=1-lft;
            lft=1;
        }else if(rgt>m){
            lft-=rgt-m;
            rgt=m;
        }
        for(int j=1;j<=len;++j){
            int to=lft+j-1;
            int cost=a[i]*to*to+b[i]*to+c[i];
            if(!mp.count(to)){
                mp[to]=++tot;
                add_flow(tot,t,0);
            }
            to=mp[to];
            add_flow(i,to,cost);
        }
    }
    mcmf();
}

int32_t main(){
    ios::sync_with_stdio(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
}