// #include<bits/stdc++.h>
// using namespace std;

// int a[10006];

// int main(){
//     int n;
//     while(scanf("%d",&n)!=EOF&&n!=0){
//         for(int i=1;i<=n;i++){
//             scanf("%d",&a[i]);
//         }
//         sort(a+1,a+n+1);
//         int ans=a[1]+a[2];
//         for(int i=3;i<=n;i++){
//             ans=ans*2+a[i];
//         }
//         printf("%d\n",ans);
//     }
// }
   

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) return 0;
		priority_queue<int, vector<int>, greater<int>> q;
		while (n--) {
			int fruit;
			scanf("%d", &fruit);
			q.push(fruit);
		}
		int ans = 0;
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