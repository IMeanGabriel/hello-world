#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
 
long long n, k;
long long arr[MAXN];
bool vis[MAXN];
vector<int> cir;
long long ans[MAXN];
 
long long getpow(long long x, long long y, long long mod) {
    long long res = 1;
    long long tmp = x % mod;
    while (y) {
        if (y & 1) {
            res *= tmp;
            res %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        y >>= 1;
    }
    return res;
}
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(vis, 0, sizeof(vis));
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }
        int pos = i;
        int cnt = 0;
        cir.clear();
        while (!vis[pos]) {
            cnt++;
            vis[pos] = true;
            cir.push_back(pos);
            pos = arr[pos];
        }
        long long tmp = 0;
        for (int j = 0; j < cnt; ++j) {
            if ((long long)(j * k) % cnt == 1) {
                tmp = j;
                break;
            }
        }
        for (int j = 0; j < cnt; ++j) {
            ans[cir[j]] = cir[(j + tmp) % cnt];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
 
/*
3 998244353
2 3 1
*/