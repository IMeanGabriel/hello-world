#include<stdio.h>
#define N 50010
int main()
{
	int T;
	scanf("%d",&T);
	
	long long p[N],a[N],pmax=0,a_pmax=0,pmin=0;
	float t_square[N],tmin;
	int k;
	int n,i,j,i_tmin;
	
	while(T--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%lld%lld",&p[i],&a[i]);
		
		k=1;		
		pmax=0;
		pmin=0;
		
		for(i=0;i<n;i++)
		if(p[i]>pmax)
		{
			pmax=p[i];
			a_pmax=a[i];
		}
		
		for(i=0,j=0;i<n;i++)
		if(a[i]>a_pmax)
		{
			p[j]=p[i];
			a[j]=a[i];
			j++;
		}
		n=j;

		while(1)
		{
			tmin=1000000;
			pmax-=pmin;
			for(i=0;i<n;i++)
			{
				p[i]-=pmin;
				t_square[i]=(pmax-p[i])*1.0/(a[i]-a_pmax);
				if(t_square[i]<tmin)
				{
					tmin=t_square[i];
					i_tmin=i;
				}
			}
			a_pmax=a[i_tmin];
	
			pmin=100000000;
			pmin=0;
			for(i=0,j=0;i<n;i++)
			if(a[i]>a_pmax)
			{
				p[j]=p[i]+a[i]*t_square[i];
				a[j]=a[i];
				
				if(p[j]>pmax)
				{
					pmax=p[j];
					a_pmax=a[j];
				}
				if(p[j]<pmin)
				pmin=p[j];
				
				j++;
			}
			n=j;
			k++;
	
			if(n==0) break;
		}


		printf("%d\n",k);
	}
	
	return 0;
}
