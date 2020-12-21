#include<cstdio>
#include<queue>
#include<cmath>

using namespace std;

const int MAXN = 1e5+10;

int cnt[MAXN*100], a[MAXN*2];
bool vis[MAXN*100];

void Getp(int n) {
    int q = sqrt(n);
    for(int i=2;i<=q;++i) {
        if(n%i==0) {
            ++cnt[i];
            if(i*i!=n) ++cnt[n/i];
        }
    }
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0;i<n;++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
        vis[a[i]] = true;
    }
    for(int i=0;i<n;++i) {
        Getp(a[i]);
    }
    int lim = 1e7+1, mxcnt = 0;
    for(int i=2;i<lim;++i) {
        if(vis[i] && cnt[i] > mxcnt) {
            mxcnt = cnt[i];
        }
    }
    mxcnt += cnt[1];
    printf("%d\n", mxcnt);
}