#include<bits/stdc++.h> 
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
    while(T--)
    {
        long long b,n;
        scanf("%lld%lld",&b,&n);
        if(b%n==1)
            printf("T\n");
        if(b%n!=1)
            printf("F\n");
    }

	return 0;
}
