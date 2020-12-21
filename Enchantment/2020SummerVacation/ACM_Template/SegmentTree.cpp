// #include<bits/stdc++.h>
// using namespace std;
// const int MOD=10000006;
// #define ll long long

// struct SegmentTree
// {
//     int ans,Max,Min;
//     struct Data
//     {
//         int Left,Right;
//         int Val;
//         int Max,Min;
//         int AddTag,MulTag;
//     } infor[4*MAXN];
// }

#include<bits/stdc++.h>
using namespace std;
long long a[1000006],sum[4000006],lazy[4000006];
int n,m,x,y,k,c;

void pushdown(int pos,int left,int right)
{
	int mid=(left+right)/2;
	sum[pos*2]+=(mid-left+1)*lazy[pos];
	sum[pos*2+1]+=(right-mid)*lazy[pos];
	lazy[pos*2]+=lazy[pos];
	lazy[pos*2+1]+=lazy[pos];
	lazy[pos]=0; 
}

void build(int pos,int left,int right)
{
	int mid=(left+right)/2;
	if(right==left)
	{
		sum[pos]=a[left];
		return;
	}

	build(pos*2,left,mid);
	build(pos*2+1,mid+1,right);
	sum[pos]=sum[pos*2]+sum[pos*2+1];
 } 

long long query(int pos,int left,int right,int q_left,int q_right)
{
	long long ans=0;
	if(q_left<=left&&q_right>=right)
		return sum[pos];
	if(lazy[pos])
		pushdown(pos,left,right);
	int mid=(left+right)/2;

	if(q_left<=mid)
		ans+=query(pos*2,left,mid,q_left,q_right);
	if(q_right>=mid+1)
		ans+=query(pos*2+1,mid+1,right,q_left,q_right);
	return ans;
}

void add(int pos,int left,int right,int x,int y,int k)
{
	if(x<=left&&y>=right)
	{
		lazy[pos]+=k;
		sum[pos]+=(right-left+1)*k;
		return;
		}
	if(lazy[pos])
		pushdown(pos,left,right);
	int mid=(left+right)/2;
	if(x<=mid)
		add(pos*2,left,mid,x,y,k);
	if(y>=mid+1)
		add(pos*2+1,mid+1,right,x,y,k); 
	sum[pos]=sum[pos*2]+sum[pos*2+1];
	/*sum[pos]+=k;
	int mid=(left+right)/2;
	if(left==right)
		return;
	if(x<=mid)
		add(pos*2,left,mid,x,k);
	else
		add(pos*2+1,mid+1,right,x,k);
	*/
}

int main()
{

	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(m--)
	{

		cin>>c;
		if(c==1)
		{

			cin>>x>>y>>k;
			add(1,1,n,x,y,k);
		}
		else
		{
			int q_left;
			int q_right;
			cin>>q_left>>q_right;
			cout<<query(1,1,n,q_left,q_right)<<endl;
		}
	}
	return 0;
}