#include<bits/stdc++.h>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
int main()
{
	int i,j,n,m,k,mark;
	int number[121][101];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(number,0,sizeof(number));			
		
		for(i=1;i<=n;++i)
		{
		number[1][1]=1; 	
			for(j=min(i-1,m);j>=1&&n-i>=m-j;--j)
			{
				for(k=1;k<=120;++k)
					number[k][j]=number[k][j-1]+j*number[k][j];
				for(k=1;k<=120;++k)
					if(number[k][j]>=10)
					{		
						number[k+1][j]+=number[k][j]/10;
						number[k][j]%=10;
					}number[1][i]=1;
			}
		}
	mark=120;
		for(i=120;i>=0;--i)
			if(number[i][m]!=0)
			{
				mark=i;
				break;
			}
		if(mark==120)mark=1;
		for(i=mark;i>=1;--i)
			printf("%d",number[i][m]);
		printf("\n");
	}
	return 0;
}
