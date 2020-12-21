#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

const int MAXN=200005;
const int INF=0x3f3f3f3f;
unordered_map<char, long long> mp;
char ss[MAXN], fh[3];
long long num[3];
void work(long long b) {
    int len=strlen(ss), cur=0;
    for(int i=0;i<3;++i) {
        num[i] = 0; 
        do {
            num[i] *= b;
            num[i] += mp[ss[cur]];
        } while(++cur<len && mp.count(ss[cur]));
        fh[i] = ss[cur]; ++cur;
    }
}
bool check() {
    if(fh[0]=='+') {
        if(num[0]+num[1]==num[2]) return true;
    }
    else if(fh[0]=='-') {
        if(num[0]-num[1]==num[2]) return true;
    }
    else if(fh[0]=='*') {
         if(num[0]*num[1]==num[2]) return true;
    }
    else if(fh[0]=='/') {
        if(num[1]==0) return false;
        if((num[0]%num[1])==0 && num[0]/num[1] == num[2]) return true;
    }
    return false;
}
int main() {
    mp['0']=0ll, mp['1']=1ll, mp['2']=2ll, mp['3']=3ll, mp['4']=4ll,
    mp['5']=5ll, mp['6']=6ll, mp['7']=7ll, mp['8']=8ll, 
    mp['9']=9ll, mp['A']=10ll, mp['B']=11ll, mp['C']=12ll, 
    mp['D']=13ll, mp['E']=14ll, mp['F']=15ll;
    while(~scanf("%s", ss)) {
        int len=strlen(ss);long long mx=1ll;
        for(int i=0;i<len;++i) {
            if(mp.count(ss[i])) {
                if(mp[ss[i]]>mx) mx=mp[ss[i]];
            }
        }
        int flag=1;
        for(long long i=mx+1;i<=16;++i) {
            work(i);
        //    printf("%d %c %d %d\n",num[0],fh[0],num[1],num[2]);
            if(check()) {
                printf("%lld\n", i);
                flag=0;
                break;
            }
        }
        if(flag)printf("-1\n");
    }
    return 0;
}