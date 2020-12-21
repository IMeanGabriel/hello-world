// #include <bits/stdc++.h>
// using namespace std;
// int m,n,flg[506];
// pair <int,int > score[506];

// int main()
// {
//     while(scanf("%d",&m)!=EOF){
//         scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//         cin>>score[i].second;
//     for(int i=1;i<=n;i++)
//         cin>>score[i].first;
//     sort(score+1,score+n+1);
//     for(int i=n;i>=1;i--)
//     {
//         int level;
//         for(level=score[i].second-1;flg[level]!=0&&level!=0;level--);
//         if(flg[level]!=0)
//         {
//             m=m-score[i].first;
//             continue;
//         }
//         flg[level]=1;
//     }
//     cout<<m<<endl;
//     }
//     return 0;
// }

#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		priority_queue<int, vector<int>, greater<int>> q;
		while (n--) {
			int x;
			scanf("%d", &x);
			q.push(x);
		}
		int ans = 0;//带权路径和，可能结果超出整型
		while (q.size() > 1) {
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			ans += a + b;
			q.push(a + b);
		}
		printf("%d\n", ans);
 
		
	}
}