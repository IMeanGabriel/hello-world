#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;


int main(){
	int T;
	scanf("%d",&T);
	while(T--)
    {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        if(abs(a-b)<=k)
            printf("1\n");
        else if(a==1)
        {
            if(b!=k+2)
                printf("1\n"); 
            else
                    printf("0\n");
        }
        else if(b==1)
        {
            if(a!=k+2)
                printf("1\n");
            else
                printf("0\n");
        }
        else if(a==k+2||b==k+2)
                printf("1\n");
        else if(a>1&&b>k+2)
            {
                printf("0\n");
                
            }
        else if(b>1&&a>k+2)
            {
                printf("0\n");
                
            }
        else if(a==0||b==0)
            printf("1\n");
        
	}
	return 0;
}

1518