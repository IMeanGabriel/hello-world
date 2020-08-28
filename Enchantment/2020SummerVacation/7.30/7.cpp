#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e5+5;
int x[N],y[N];
int head[N],to[N],match[N],nxt[N];//head,nxt,to����ʽǰ���Ǵ�ͼ��macth��������¼����ͼ���Ұ�ߵ�����ʣ����˭����ƥ���� 
map<int,int>m1,m2; 
int cnt,cnt1,cnt2;//cnt�Ǳߵ���ţ�cnt1����ߵ����ţ�cnt2���ұߵ����� 
bool vis[N];
void AddEdge(int f,int t){//��ʽǰ���Ƕ���ͼƥ�䶼�ǵ������ӣ������ָ���ұߵĵ� 
	to[++cnt]=t;
	nxt[cnt]=head[f];
	head[f]=cnt;
} 
int DFS(int u){//����ƥ��
	int v;
	for(int i=head[u];i;i=nxt[i]){//��������������бߵĵ� 
		v=to[i];
		if(!vis[v]){
			vis[v]=1;//û���ʵĻ���� 
			if(match[v]==-1||DFS(match[v])){//����ұߵĵ�û�б�ƥ������������ƥ���Ѿ���ǰ��ĵ�ƥ����ˣ������Ȱ�u,v,�ճ�һ�ѣ�Ȼ����match[v]��¼�ĵ�ȥ�����ܲ��ܺ�����������ƥ�䣬�ѵ�ǰ��v�ó��� 
				match[v]=u;//�ҵ��ˣ����ݵ�ʱ��͸�match[v] 
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
		m1.clear(),m2.clear();//�����еĵ��ʼ�� 
		for(int i=1;i<=n;i++)	head[i]=0;//ͼ�γ�ʼ�� 
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);//��ͼ 
			int k1=x[i]+y[i],k2=x[i]-y[i];
			if(m1[k1]==0)	m1[k1]=++cnt1;//��ߵĵ����� 
			if(m2[k2]==0)	m2[k2]=++cnt2; //�ұߵ����� 
			AddEdge(m1[k1],m2[k2]); //���������� 
		}
		for(int i=1;i<=cnt2;i++)	match[i]=-1;//��ʼ��ƥ���ұߵ���� 
		for(int i=1;i<=cnt1;i++){//��ÿ����ߵĵ����ұ��ܺ���ƥ��ĵ� 
			memset(vis,0,sizeof(vis));//ÿ��ƥ�䶼Ҫ��ʼ���� 
			if(DFS(i))//�ҵ���һ��ƥ�� 
				ans++;
		} 
		cout<<ans<<"\n";
	}
} 
