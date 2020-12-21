#include<cstdio>
#include<cstring>
using namespace std;
int cnt[30];

int main(){
	int T,T0;
	scanf("%d",&T);
	getchar();
	for(T0=1;T0<=T;++T0){		
		memset(cnt,0,sizeof(cnt));
		char a;		
		while(1){
			scanf("%c",&a);
			if(a=='\n') break;
			cnt[a-'a']++;
		}
		
		int maxcnt=0;
		for(int i=0;i<26;++i){
			if(cnt[i]>maxcnt) maxcnt=cnt[i];
		}
		
		printf("Case #%d: %d\n",T0,maxcnt);
	}
	return 0;
}
