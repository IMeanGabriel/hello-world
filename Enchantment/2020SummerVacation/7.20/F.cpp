#include<iostream>
#define max(a,b) ((a)>(b)?a:b)
using namespace std;

int main()
{
	int N, K, i, j, k, a[100], sum[100];	
	cin >> N >> K;
    sum[0] = 0;
	for (i = 1; i <= N; i++)
	{
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
	}
    long long dp[100][100];
    for (i = 1; i <= N; i++)
        dp[i][0] = sum[i];
	for (i = 2; i<=N; i++)	
    {
        for (j = 1; j <= K; j++)	
        {
            if (j>i-1)
                break;	
            for (k = 2; k<=i; k++)
                dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] * (sum[i] - sum[k - 1]));
		}
	}
	cout << dp[N][K];
	return 0;
}
