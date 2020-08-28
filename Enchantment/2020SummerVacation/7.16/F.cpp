// #include <bits/stdc++.h>
// #define N 5010
// #define ll long long
// using namespace std;
 
// ll ans=0;
// int n,m,k;
// int a[N][N],mx[N][N];
// bool vis[N][N];
 
// struct node
// {
//     int val,ind;
// }q[N];
 
// int main()
// {
//     cin>>n>>m>>k;
//     for (int i=1;i<=n;i++)
//     {
//         for (int j=1;j<=m;j++)
//         {
//             if (!vis[i][j])
//             {
//                 for (int k=1;k*i<=n && k*j<=m;k++)
//                 {
//                     vis[i*k][j*k]=1;
//                     a[i*k][j*k]=i*j*k;
//                 }
//             }
//         }
//     }
//     for (int j=1;j<=m;j++)
//     {
//         int f=1,r=1;
//         q[1].ind=1;q[1].val=a[1][j];
//         for (int i=2;i<=k;i++)
//         {
//             while (a[i][j]>q[r].val && r>0) r--;
//             q[++r].ind=i;q[r].val=a[i][j];
//         }
//         mx[1][j]=q[1].val;
//         for (int i=2;i<=n-k+1;i++)
//         {
//             while (q[f].ind<i && f<=r) f++;
//             while (f<=r && q[r].val<a[i+k-1][j]) r--;
//             q[++r].ind=i+k-1;q[r].val=a[i+k-1][j];
//             mx[i][j]=q[f].val;
//         }
//     }
//     for (int i=1;i<=n-k+1;i++)
//     {
//         int f=1,r=1;
//         q[1].ind=1;q[1].val=mx[i][1];
//         for (int j=2;j<=k;j++)
//         {
//             while (mx[i][j]>q[r].val && r>0) r--;
//             q[++r].ind=j;q[r].val=mx[i][j];
//         }
//         ans+=q[1].val;
//         for (int j=2;j<=m-k+1;j++)
//         {
//             while (q[f].ind<j && f<=r) f++;
//             while (f<=r && q[r].val<mx[i][j+k-1]) r--;
//             q[++r].ind=j+k-1;q[r].val=mx[i][j+k-1];
//             ans+=q[f].val;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }


#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
int a[5010][5010]={0};
int  M[5010][5010]={0};
int n,m,k;
long long ans=0;
void pre(int r,int c){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++)
            if(a[i][j]==0){
                a[i][j]=i*j;
                for(int k=2;;k++){
                    int nx=k*i,ny=k*j;
                    if(nx>r||ny>c)    break;
                    a[nx][ny]=k*a[i][j];
                }
                     
            }
    }
}
void side_window(int *p,int len,int c){
    deque<int>Q;
    for(int i=1;i<=m;i++){
        while(!Q.empty()&&p[i]>Q.back())
            Q.pop_back();
        Q.push_back(p[i]);
        if(i>len&&p[i-len]==Q.front() ){
            Q.pop_front();
        }
        if(i>=len)
            M[c][i]=Q.front();
    }
}
void slove(int c,int len){
    deque<int>Q;
    for(int i=1;i<=n;i++){
        while(!Q.empty()&&M[i][c]>Q.back())
            Q.pop_back();
        Q.push_back(M[i][c]);
        if(i>len&&M[i-len][c]==Q.front())
            Q.pop_front();
        if(i>=len)
            ans=ans+Q.front();
    }
}
int main(){
    cin>>n>>m>>k;
    pre(n,m);
    for(int i=1;i<=n;i++)
        side_window(a[i],k,i);
    for(int i=k;i<=m;i++)
        slove(i,k);
    cout<<ans<<endl;
}