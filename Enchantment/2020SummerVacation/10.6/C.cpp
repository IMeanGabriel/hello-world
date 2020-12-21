#include<cstdio>
using namespace std;
const int N=1010;
int n,a[N];
struct DP{
	int a;
	int len;//a[i]结尾的最长降序子序列长度 
	int pre;//最长降序子序列中a[i]的前一个数下标 
	int pos;//a[i]在数列a降序排列后的位置
	int cost;//=原序列位置+排序后位置
	long long s_cost;//a[i]结尾的最长降序子序列的移动cost和 
}dp[N];

int main(){	
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&dp[i].a);			
		}
		for(int i=1;i<=n;++i){
			dp[i].pos=1;
			for(int j=1;j<=n;++j){
				if(dp[j].a>dp[i].a){
					dp[i].pos++;
				}
			}
			dp[i].cost=i+dp[i].pos;
			dp[i].s_cost=dp[i].cost; 
		} 
				
		int max_len=0;
		long long max_cost=0,sum_cost=0;
		for(int i=1;i<=n;++i){
			dp[i].len=1;
			dp[i].pre=0;
			for(int j=1;j<i;++j){
				if(dp[j].a>dp[i].a){
					dp[i].len=dp[j].len+1;
					dp[i].pre=j;
					dp[i].s_cost=dp[j].s_cost+dp[i].cost;
				}
			}
			sum_cost+=dp[i].cost;
			if(dp[i].len>=max_len){
				max_len=dp[i].len;
				if(dp[i].s_cost>max_cost){
					max_cost=dp[i].s_cost;
				} 	
			}
			
		}
		
		printf("%lld %d\n",sum_cost-max_cost,n-max_len); 		
	}
	
	return 0;
}
