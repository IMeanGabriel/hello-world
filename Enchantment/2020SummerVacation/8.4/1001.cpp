#include<bits/stdc++.h> 
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	double ans=0.0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				ans+=(double)(1.0/i+1.0/j+1.0/k);
				printf("%lf\n",ans);
			}
		}
	}
	ans/=(double)n*n*n;

	printf("%lf",ans);
	return 0;
}
