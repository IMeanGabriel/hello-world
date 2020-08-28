#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,T;
    scanf("%d",&T);
    while(T--)
    {
        int a[100],step[100],i;
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d",&step[i]);
        }
	    for(int i=0;i<n;++i)
        {
		    a[i]=i+1;
	    }
        int cnt=0;
	    while(next_permutation(a,a+n))
        {
            int flag=0;
            for(int i=0;i<n-1;i++)
            {
                if(a[i]>a[i+1]&&step[i]!=1)
                    flag=1;
                if(a[i]<a[i+1]&&step[i]!=0)
                    flag=1;
            }
            if(flag==0)
                cnt++;
		// for(int i=0;i<n;++i){
		// 	cout<<a[i]<<" ";
        }
        printf("%d\n",cnt);
	}
    return 0;
}