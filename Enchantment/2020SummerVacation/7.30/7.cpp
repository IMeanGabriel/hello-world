#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e5+5;
int x[N],y[N];
int head[N],to[N],match[N],nxt[N];//head,nxt,to是链式前向星存图，macth是用来记录二分图中右半边点的性质，左边谁和他匹配了 
map<int,int>m1,m2; 
int cnt,cnt1,cnt2;//cnt是边的序号，cnt1是左边点的序号，cnt2是右边点的序号 
bool vis[N];
void AddEdge(int f,int t){//链式前向星二分图匹配都是单向连接，由左边指向右边的点 
	to[++cnt]=t;
	nxt[cnt]=head[f];
	head[f]=cnt;
} 
int DFS(int u){//二分匹配
	int v;
	for(int i=head[u];i;i=nxt[i]){//与这个点相连的有边的点 
		v=to[i];
		if(!vis[v]){
			vis[v]=1;//没访问的话标记 
			if(match[v]==-1||DFS(match[v])){//这个右边的点没有被匹配过或者这个点匹配已经被前面的点匹配过了，我们先把u,v,凑成一堆，然后让match[v]记录的点去看看能不能和其他点重新匹配，把当前的v让出来 
				match[v]=u;//找到了，回溯的时候就改match[v] 
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int ans=0;
		cnt=0,cnt1=0,cnt2=0;
		m1.clear(),m2.clear();//集合中的点初始化 
		for(int i=1;i<=n;i++)	head[i]=0;//图形初始化 
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);//构图 
			int k1=x[i]+y[i],k2=x[i]-y[i];
			if(m1[k1]==0)	m1[k1]=++cnt1;//左边的点的序号 
			if(m2[k2]==0)	m2[k2]=++cnt2; //右边点的序号 
			AddEdge(m1[k1],m2[k2]); //连接两个点 
		}
		for(int i=1;i<=cnt2;i++)	match[i]=-1;//初始化匹配右边点对象 
		for(int i=1;i<=cnt1;i++){//给每个左边的点找右边能和它匹配的点 
			memset(vis,0,sizeof(vis));//每次匹配都要初始化。 
			if(DFS(i))//找到了一堆匹配 
				ans++;
		} 
		cout<<ans<<"\n";
	}
} 
