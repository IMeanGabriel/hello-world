#include<bits/stdc++.h>
using namespace std;
const int MAXN=206;
int ans[MAXN];
char a[MAXN],b[MAXN],n[MAXN];
int lenc,lena,lenb;
 
int main()
{
	while(cin>>a>>b)
{	int lena=strlen(a);
	int lenb=strlen(b);
	
	int a2[MAXN]={0},b2[MAXN]={0};
    	
	if(lena<lenb||(strcmp(a,b)<0&&lena==lenb))
	{
		strcpy(n,a);
		strcpy(b,a);
		strcpy(a,b);
		cout<<"-";
	}

	for(int i=0;i<=lena-1;i++)
	{
		a2[lena-i]=a[i]-'0';
	}
	for(int i=0;i<=lenb-1;i++)
	{
		b2[lenb-i]=b[i]-'0';
	}
	
	int i=1;
    int x=0;
	while(i<=max(lena,lenb))
	{
		if(a2[lena]==0)
            lena--;
		if(a2[i]<b2[i]) 
		{
			a2[i+1]--;
			a2[i]+=10;
		}
		ans[i]=a2[i]-b2[i];
		i++;
		lenc++;
	}
	bool flg=true;
	for(int i=lenc;i>=1;i--)
	{
		if(ans[i]==0&&flg)
            continue;
		else flg=false;
		cout<<ans[i];
	}
    cout<<endl;
}	
	return 0;
}