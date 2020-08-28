#include<bits/stdc++.h>
using namespace std;

bool judge(int n)
{
	for (int i = 2; i * i<= n; ++i)
		if(n % i == 0)
			return false;
	return true;//是质数
}
 
int main()
{
	int maxn = 0;
    int minn = 106;
    int cnt[30] = {0};
	char str[106];
	gets(str);
	for (int i = 0; i < strlen(str); ++i)
		cnt[str[i] - 'a']++;
	for (int i = 0; i < 26; ++i)
	{
		if(cnt[i] > maxn)
			maxn = cnt[i];
		if (cnt[i] < minn && cnt[i] != 0)
			minn = cnt[i];
	}
	if (maxn - minn >1 && judge(maxn - minn))
		printf("Lucky Word\n%d",maxn-minn);
	else
		printf("No Answer\n0");
	return 0;
}