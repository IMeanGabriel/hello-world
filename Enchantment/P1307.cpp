// #include <bits/stdc++.h>
// using namespace std;

// int number[1006][1006], maxn, summ, n;

// void dfs(int i, int j){
//     if(i==n){
//         maxn=maxn>summ?maxn:summ;
//     }
//     else{
//         summ+=number[i+1][j];
//         dfs(i+1, j);
//         summ-=number[i+1][j];
//         summ+=number[i+1][j+1];
//         dfs(i+1, j+1);
//         summ-=number[i+1][j+1];
//     }
// }

// int main(){
//     scanf("%d", &n);
//   {  for(int i=0; i<n; i++){
//         for(int j=0; j<=i; j++){
//             scanf("%d", &number[i][j]);
//         }
//     }
//     dfs(0, 0);
//     printf("%d\n", maxn+number[0][0]);
//    } return 0;
// }

// /*
// 5
// 13
// 11 8
// 12 7 26
// 6 14 15 8
// 12 7 13 24 11
// */
// #include<iostream>
// #include<cstring>
// using namespace std;
// int f[1010][1010];//f[i][j]从第i行第j个数到最后一行的最大数字和
// int a[1010][1010];
// int main()
// {
// 	memset(a,0,sizeof(a));
// 	memset(f,0,sizeof(f));
// 	int n;
// 	cin>>n;
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=i;j++)
// 		{
// 			cin>>a[i][j];
// 		}
// 	}
// 	for(int i=1;i<=n;i++)//初始状态
// 	{
// 		f[n][i]=a[n][i];
// 	}
// 	for(int i=n;i>=1;i--)//i个阶段
// 	{
// 		for(int j=1;j<=i;j++)//j个状态
// 		{
// 			f[i][j]=a[i][j]+max(f[i+1][j],f[i+1][j+1]);//取两个方向的最大数字和
// 		}
// 	}
// 	cout<<f[1][1]<<endl;
// 	return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int n,ans=0;
// int a[1000],f[1000];

// int main()
// {
// 	while(scanf("%d",&n)!=EOF)
//     {
// 	scanf("%d",&a[1]);
// 	f[1]=a[1];
// 	for (int i=2;i<=n;i++)
// 	{
// 		for(int j=1;j<=i;j++)
// 			scanf("%d",&a[j]);
// 		for(int j=i;j>=2;j--)
// 		{
// 			f[j]=max(f[j-1],f[j])+a[j];
// 			ans=max(ans,f[j]);
// 		}
// 		f[1]=a[1]+f[1];
// 		ans=max(ans,f[1]);
// 	}
// 	printf("%d\n",ans);
//     }
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int dp[1006][1006];
int main()
{
	int n, ans = 0;
	while (cin >> n)
	{
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cin >> dp[i][j];
			}
		}
			for (int i = 2; i <= n; i++)
			{
				for (int j = 1; j <= i; j++)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + dp[i][j];
				}
			}
			for (int i = 1; i <= n; i++)
			{
				ans = (ans > dp[n][i] ? ans : dp[n][i]);
			}
			cout << ans << endl;
	}
	return 0;
}
