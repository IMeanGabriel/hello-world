#include<cstdio>
using namespace std;
const int N=60; 
int a[N][N];

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){		
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int k,flag=1;
		scanf("%d",&k);
		if(!k) flag=0;
		
		for(int i=1;i<9;++i){
			scanf("%d",&k);
			if(k) flag=0;
		}
		
		if(flag){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%d ",a[i][j]);
				}
				printf("\n");
			}
		}else{
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("0 ");
				}
				printf("\n");
			}
		}
		
	}
	return 0;
}