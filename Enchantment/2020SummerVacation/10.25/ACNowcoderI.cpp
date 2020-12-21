// #include<bits/stdc++.h>
// using namespace std;
// const int MAXN=1006;
// int mat[MAXN][MAXN]={0};

// int main()
// {
//     int T;
//     scanf("%d",&T);
//     while(T--)
//     {
//     int n,m,a,b;
//     int flg=0;
//     scanf("%d%d%d%d",&n,&m,&a,&b);
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             scanf("%d",&mat[i][j]);
//         }
//     }
//     for(int i=1;i<=n-a+1;i++)
//     {
//         for(int j=1;j<=m-b+1;j++)
//         {
//             int tmp=mat[i][j];
//             for(int k=i;k<=i+a-1;k++)
//             {
//                 for(int q=j;q<=j+b-1;q++)
//                 {
                    
//                     mat[k][q]-=tmp;
//                     if(mat[k][q]<0) flg=1;
//                 }
//             }
//         }
//     }
//     if(flg==0)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 if(mat[i][j]!=0)
//                 {
//                     flg=1;
//                     break;
//                 }
//             }
//         }
//     }
//     if(flg==1)
//     {
//         cout<<"QAQ"<<endl;
//     }
//     else
//     {
//         cout<<"^ ^"<<endl;
//     }
//     }
    
// }

#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1010;
char s[MAXN][MAXN];
bool s1[MAXN][MAXN];
int n,m;

bool dfs(int i,int j){
    //cout<<"i="<<i<<" j="<<j<<endl;
	if(i<0||i>=n||j<0||j>=m) return true;
	if(s1[i][j]) return false;
	
	s1[i][j]=true;
	if(s[i][j]=='W') return dfs(i-1,j);
	else if(s[i][j]=='A') return dfs(i,j-1);
	else if(s[i][j]=='S') return dfs(i+1,j);
	else return dfs(i,j+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%c",&s[i][j]);
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			memset(s1,false,sizeof(s1));
			if( dfs(i,j) ) printf("(%d,%d)",i+1,j+1);cnt++;
		}
	}	
	printf("%d",cnt);
	return 0;
}