#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

int main()
{
	int n;
	int num, i;
	int quantities[MAXN];
	while (scanf("%d", &n)!=EOF && n!=0)
	{
		memset(quantities, 0, sizeof(quantities));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num);
			quantities[num]++;
		}
		for (i = 1; i < MAXN; i++)
		{
			if (quantities[i] % 2)
			{
				cout<<"Win"<<endl;
				break;
			}
		}
		if (i >= MAXN)
			cout<<"Lose"<<endl;
	}
	return 0;
}