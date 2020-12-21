#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e5;
int mul[MAXN]; 
int n,k;

int  qpow(long long a, int b) {
	long long ans=1;
	while(b) {
		if(b&1) ans*=a;
		if(ans>n) return 0;
		a*=a;
		b>>=1;
	}
	return (int)ans;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int T0=1;T0<=T;T0++){
		scanf("%d%d",&n,&k);
		memset(mul,0,sizeof(mul));
		
		if(k==1){
			printf("Case #%d: %d\n",T0,n);
			continue;
		}
		
		int i;
		for(i=1;;i++){
			mul[i]=qpow(i,k);
			if(mul[i]==0) break;
		}
		
//		for(i=1;mul[i]!=0;i++){
//			printf("%lld ",mul[i]);
//		}
//		printf("\n");
		
		int ans=0;
		for(i=2;mul[i]!=0;i++){
			ans+=(mul[i]-mul[i-1])/(i-1);
			ans+=(mul[i]-mul[i-1])%(i-1)==0?0:1;
		}
		ans+=(n-mul[i-1]+1)/(i-1);
		ans+=(n-mul[i-1]+1)%(i-1)==0?0:1;
			
		printf("Case #%d: %d\n",T0,ans);		
	
	}	
	return 0;
} 
