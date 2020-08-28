// #include<bits/stdc++.h>
// using namespace std;

// char a[106];
// char b[106];
// long long ans[306];

// int main()
// {
// 	int mark;
// 	while(scanf("%s%s",&a,&b)!=EOF)
// 	{
// 		memset(ans,0,sizeof(ans));
// 		int lena=strlen(a)-1;
// 		int lenb=strlen(b)-1;
// 		int len=lena+lenb;
// 		for(int i=lena;i>=0;i--)
// 		{
// 			for(int j=lenb;j>=0;j--)
// 				ans[lena-i+lenb-j]+=(a[i]-'0')*(b[j]-'0');
// 			for(int k=lena-i;k<=len-i;k++)
// 			{
// 				if(ans[k]>=10)
// 				{
// 					ans[k+1]+=ans[k]/10;
// 					ans[k]%=10;
// 				}
// 			}
// 		}
// 		for(int i=305;i>=0;i--)
// 		{
// 			if(ans[i]!=0)
// 			{
// 				mark=i;
// 				break;
// 			}
// 		}
// 		for(int i=mark;i>=0;i--)
// 		{
// 			printf("%lld",ans[i]);
// 		}
// 		printf("\n");
// 	}
// 	return 0;
//  } 
#include<bits/stdc++.h>
using namespace std;

char num1[106];
char num2[106];
long long ans[306];

int main()
{
	int mark;
	while(scanf("%s\n%s",&num1,&num2)!=EOF)
	{
		memset(ans,0,sizeof(ans));
		int lena=strlen(num1)-1;
		int lenb=strlen(num2)-1;
		int len=lena+lenb;
		for(int i=lena;i>=0;i--)
		{
			for(int j=lenb;j>=0;j--)
				ans[len-i-j]+=(num1[i]-'0')*(num2[j]-'0');
			for(int k=lena-i;k<=len-i;k++)
			{
				if(ans[k]>=10)
				{
					ans[k+1]+=ans[k]/10;
					ans[k]%=10;
				}
			}
		}
		for(int i=305;i>=0;i--)
		{
			if(ans[i]!=0)
			{
				mark=i;
				break;
			}
		}
		for(int i=mark;i>=0;i--)
		{
			printf("%lld",ans[i]);
		}
		printf("\n");
	}
	return 0;
 } 