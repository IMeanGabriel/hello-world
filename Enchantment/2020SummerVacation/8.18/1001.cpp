#include<cstdio>
using namespace std;
const int MAXN=5e5+10;
struct vertice{
	int parent;
	int reach;
	int layer;
}v[MAXN];

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		
		v[1].layer=v[1].reach=1;
		int max_layer=0,i_max_layer;
		for(int i=2;i<=n;i++){
			v[i].reach=1;
			scanf("%d",&v[i].parent);
			v[i].layer=v[v[i].parent].layer+1;
			
			if(v[i].layer>max_layer){
				max_layer=v[i].layer;
				i_max_layer=i;
			}			
		}
		
		for(int i=n;i>=2;i--){
			v[v[i].parent].reach+=v[i].reach;
		}
		
		for(int i=i_max_layer;i>=1;){
			v[i].reach=n;
			i=v[i].parent;
		} 
		
		long long ans=0;
		for(int i=1;i<=n;i++){			
			ans+=v[i].reach;
			//printf("%d%c",v[i].reach,i==n?'\n':' ');
		}

		printf("%lld\n",ans);
	}
	return 0;
}
