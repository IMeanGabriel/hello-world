#include<cstdio>

using namespace std;

const int MAXN=1e6+5;
const int INF=0x3f3f3f3f;

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        long long x[4], y[4];
        for(int i=1;i<=3;++i) {
            scanf("%lld%lld", &x[i], &y[i]);
        }
        long long ans=(x[2]-x[1])*(y[3]-y[1])-(x[3]-x[1])*(y[2]-y[1]);
        printf("%lld\n",ans);
        if(ans>0ll) printf("Counterclockwise\n");
        else printf("Clockwise\n");
    }
    return 0;
}