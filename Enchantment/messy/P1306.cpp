#include <bits/stdc++.h>
using namespace std;
const int MAXN = 106;
const int MAX = 10006;

int main(void)
{  
    int volumn[MAX];
    int w[MAX];
    int dp[MAX];
    int n, c;
    while(cin >> n >> c)
    {
        for(int i = 1; i <= n; ++i)
        {
            cin >> volumn[i] >> w[i];
        }
        memset(dp, 0, sizeof(dp));
    	int ans = 0;
    	for(int j = 1;j <= n; ++j)
    	{
        	for(int i = volumn[j]; i <= c; ++i)
        	{
            	dp[i] = max(dp[i], dp[i - volumn[j]] + w[j]);
            	if(ans<dp[i])
                {
                    ans=dp[i];
                }
        	}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}