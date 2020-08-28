// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     long long t;
//     scanf("%d",&n);
//     while(n--)
//     {
//         scanf("%lld",%)
//     }
// }
#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	int i,n;
	while(T--){
		scanf("%d",&n);
		if(n==1) n=26;
		else if(n==2) n=26*25+26;
		else if(n==3) n=26*25*24+26*25/2*2*3+26;
		else n=26*25*24;
		printf("%d\n",n);
	}
	
	return 0;
} 
