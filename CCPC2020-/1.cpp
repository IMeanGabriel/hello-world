#include<cstdio>
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b); 
}
int main(){
	int T;
	scanf("%d",&T);
	for(int T0=1;T0<=T;T0++){
		int r,b;
		scanf("%d%d",&r,&b);
		int fenzi=r*(r-1);
		int fenmu=(r+b)*(r+b-1);
		int x=gcd(fenzi,fenmu);
		if(r<2){
			printf("Case #%d: %d/%d\n",T0,0,1);
		}else if(b==0){
			
		}else{
			printf("Case #%d: %d/%d\n",T0,fenzi/x,fenmu/x);
		}
	}
	return 0;
} 
