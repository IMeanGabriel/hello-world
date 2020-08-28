// #include<bits/stdc++.h>
// int n,p[100]={1,1},a[50],b[20];

// void dfs(int s)
// {
//     if(s==n+1&&p[a[1]+a[n]]==0)
//     {
//         for(int i=1;i<n;i++)
//           printf("%d ",a[i]);
//           printf("%d\n",a[n]);
//         return ;
//     }
//     for(int i=2;i<=n;i++)
//     {
//         if(b[i]==0&&p[i+a[s-1]]==0)
//         {
//             a[s]=i;
//             b[i]=1;
//             dfs(s+1);
//             b[i]=0;
//         }
//     }
//     return ;
// }

// int main()
// {
//     int t=1;
//     for(int i=2;i<=10;i++)
//      if(p[i]==0)
//         for(int j=2*i;j<=40;j+=i)
//          p[j]=1;
//     a[1]=1;
//     while(scanf("%d",&n)!=EOF)
//     {
//         if(n==0) break;
//         memset(b,0,sizeof(b));
//         printf("Case %d:\n",t++);
//         if(n%2==0||n==1)
//            dfs(2);
//         else
//             printf("\n");
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// bool checkprime[45]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0};
// int n;
// int a[22],num[22];
// void dfs(int x){
// 	if(x==n+1&&checkprime[num[n]+num[1]])
//     {
// 	  for(int i=1;i<=n;++i)
// 		  printf("%d ",num[i]);
// 	  printf("\n");
// 	}
// 	else for(int i=2;i<=n;++i)
// 			if(!a[i]&&checkprime[i+num[x-1]])
//             {
// 			  a[i]=1;
//               num[x]=i;
// 			  dfs(x+1);
//               a[i]=0;
// 			}
// }

// int main()
// {
// 	int k=0;
//  while(scanf("%d",&n)!=EOF&&n!=0)
//  {
// 	 printf("Case %d:\n",++k);
// 	 if(n==1)
//         printf("1\n");
// 	 else if(n%2)
//      {
//          printf("No Answer\n");
//     }
// 	else
//     {
// 	  memset(a,0,sizeof(a));
// 	  num[1]=1;
//       dfs(2);
// 	}
//   }
//   return 0;
// }

// #include <bits/stdc++.h>
// using namespae std;

// int a[21]={1};
// bool a[21];
// int n;

// bool checkprime(int x)
// {
// 	int i;
// 	for(i=2;i*i<=x;i++)
// 	{
// 		if(x%i==0)return false;
// 	}
// 	return true;
// }

// void DFS(int x)
// {
// 	int i;
// 	if(x==n-1)
// 	{
// 		if(checkprime(a[x]+1))
// 		{
// 			printf("1");
// 			for(i=1;i<n;i++)
// 				printf(" %d",a[i]);
// 				puts("");
// 			return;
// 		}
// 	}

// 	for(i=2;i<=n;i++)
// 	{

// 		if(!a[i] && checkprime(a[x]+i))
// 		{
// 			a[i]=1;
// 			a[x+1]=i;
// 			DFS(x+1);
// 			a[i]=0;
// 		}
// 	}
// }
// int main()
// {
// 	int i;
// 	int Case=1;
// 	while(scanf("%d",&n),n)
// 	{
// 		memset(a,0,sizeof(a));

// 		printf("Case %d:\n",Case++);
// 		if(n%2==0 || n==1 )
// 			DFS(0);
// 		else printf("\n");
// 	}
// 	return 0;
// }

// #include <bits/stdc++.h>
// int n,a[21]={1};
// bool vis[21];
// bool checkprime(int x)
// {
//     for(int i=2;i*i<=x;i++)
//         if(x%i==0)
//             return false;
//     return true;
// }
// void dfs(int now)
// {
//     if(now == n-1)
//     {
//         if(checkprime(a[now]+1))
//         {
//             printf("1");
//             for(int i=1;i<n;i++)
//                 printf(" %d",a[i]);
//             printf("\n");
//         }
//         return ;
//     }
//     for(int i=2;i<=n;i++)
//     {
//         if(!vis[i] && checkprime(i+a[now]))
//         {
//             vis[i]=1;
//             a[now+1]=i;
//             dfs(now+1);
//             vis[i]=0;
//         }
//     }
// }
// int main()
// {
//     int ncase=0;
//     while(scanf("%d",&n),n)
//     {
//         printf("Case %d:\n",++ncase);
//         memset(vis,0,sizeof(vis));
//        if(n%2==0 || n==1)
//             dfs(0);
//         else
//             printf("\n");
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;

int n, a[MAXN];
bool vis[MAXN];

bool check(int n)
{
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29 || n == 31)
        return true;
    return false;
}

void dfs(int now)
{
    if (n - 1 == now)
    {
        if (check(a[now] + 1))
        {
            printf("1");
            for (int i = 1; i < n; i++)
            {
                printf(" %d", a[i]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && check(i + a[now]))
        {
            vis[i] = 1;
            a[now + 1] = i;
            dfs(now + 1);
            vis[i] = 0;
        }
    }
}

int main()
{

    int t = 1;
    while (scanf("%d", &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        a[0] = 1;
        vis[1] = 1;
        printf("Case %d:\n", t++);
        dfs(0);
        printf("\n");
    }
    return 0;
}
// int main()
// {
//     int ncase=0;
//     while(scanf("%d",&n),n)
//     {
//         printf("Case %d:\n",++ncase);
//         memset(a,0,sizeof(a));
//        if(n%2==0 || n==1)
//             dfs(0);
//         else
//             printf("\n");
//     }
//     return 0;
// }