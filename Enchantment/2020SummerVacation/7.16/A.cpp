// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <unordered_map>
// #include <vector>
// typedef unsigned long long ull;
// using namespace std;
// const int MOD = 998244353;
// const int MAXN = 1e6 + 10;
// const int BASE = 257;
// int n, cnt[MAXN];
// vector<int> pai[MAXN];
// vector<ull> hsh[MAXN];
// ull P[MAXN];
// string s[MAXN];
// unordered_map<ull, int> mp;
 
// int main() {
//     // freopen("in", "r", stdin);
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     P[0] = 1;
//     for (int i = 1; i < MAXN; ++i) P[i] = P[i - 1] * BASE;
 
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         cin >> s[i];
//         // for (auto &c : s[i]) c -= '0';
 
//         int len = s[i].length();
//         pai[i].resize(len);
//         hsh[i].resize(len);
         
//         // get pai(or next) array
//         pai[i][0] = 0;
//         int p = 0;
//         for (int j = 1; j < len; ++j) {
//             while (p > 0 && s[i][p] != s[i][j]) p = pai[i][p - 1];
//             if (s[i][p] == s[i][j]) {
//                 pai[i][j] = ++p;
//             } else {
//                 pai[i][j] = p;
//             }
//         }
 
//         // get hash array
//         hsh[i][0] = s[i][0];
//         for (int j = 1; j < len; ++j) {
//             hsh[i][j] = hsh[i][j - 1] * BASE + s[i][j];
//         }
//         ++mp[hsh[i][len - 1]];
//         for (int j = 1; j < len; ++j) {
//             ull h = hsh[i][len - 1] - (hsh[i][j - 1] * P[len - j]);
//             ++mp[h];
//         }
//     }
     
 
//     ull ans = 0;
//     for (int i = 0; i < n; ++i) {
//         const int &len = s[i].length();
//         // memset(cnt, 0, sizeof(cnt));
//         for (int j = 0; j < len; ++j) {
//             cnt[j] = mp[hsh[i][j]];
//             if (pai[i][j] >= 1) cnt[pai[i][j] - 1] -= cnt[j];
//         }
//         for (int j = 0; j < len; ++j) {
//             ans = (ans + (1ull * (j + 1) * (j + 1) % MOD * cnt[j]) % MOD) % MOD;
//         }
//     }
//     cout << ans << '\n';
 
//     return 0;
// }







// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <vector>
 
// constexpr unsigned long long HASH_CONST_A = 12345678909827;
// constexpr unsigned long long HASH_CONST_B = 19260817;
// constexpr unsigned long long HASH_MOD     = 1ull << 63;
// constexpr unsigned long long ANS_MOD      = 998244353;
 
// std::vector<size_t> get_next_vector(const std::string &s)
// {
//     std::vector<size_t> next(s.length(), 0);
//     size_t              j = 0;
//     for(size_t i = 1; i < s.length(); ++i)
//     {
//         while(s.at(i) != s.at(j) && j != 0)
//         {
//             j = next.at(j-1);
//             // j = next.at(j);
//         }
//         if(s.at(i) == s.at(j))
//         {
//             ++j;
//         }
//         next[i] = j;
//     }
//     return next;
// }
 
// unsigned long long suffixHash(char                      cur,
//                               unsigned long long        last,
//                               const unsigned long long &A,
//                               const unsigned long long &B)
// {
//     return last + A * (cur + B);
// }
 
// unsigned long long prefixHash(char                      cur,
//                               unsigned long long        last,
//                               const unsigned long long &A,
//                               const unsigned long long &B)
// {
//     return last * A + (cur + B);
// }
 
// int main(void)
// {
//     size_t n;
//     while(std::cin >> n)
//     {
//         std::unordered_map<unsigned long long, unsigned long long> hashBucket;
//         std::vector<std::string>                                   strings;
//         {
//             strings.clear();
//             strings.resize(n);
//             for(size_t i = 0; i < n; ++i)
//             {
//                 std::cin >> strings[i];
//             }
//         }  // Input
 
//         {
//             for(const auto &s: strings)
//             {
//                 unsigned long long A       = 1;
//                 unsigned long long curHash = 0;
//                 for(size_t i = s.length() - 1; ~i; --i)
//                 {
//                     const auto c = s.at(i);
//                     curHash      = suffixHash(c, curHash, A, HASH_CONST_B);
//                     ++(hashBucket[curHash]);
//                     A *= HASH_CONST_A;
//                 }
//                 // std::cout << curHash << std::endl;
//             }
//         }  // Hash
//         {
//             unsigned long long ans = 0;
//             // unsigned long long sum = 0;
//             for(const auto &s: strings)
//             {
//                 std::vector<unsigned long long> cnt;
//                 auto                            next    = get_next_vector(s);
//                 unsigned long long              curHash = 0;
//                 for(const auto &c: s)
//                 {
//                     curHash = prefixHash(c, curHash, HASH_CONST_A, HASH_CONST_B);
//                     if(hashBucket.count(curHash))
//                     {
//                         cnt.push_back(hashBucket[curHash]);
//                     }
//                     else
//                     {
//                         cnt.push_back(0);
//                     }
//                 }
//                 for(size_t i = 0; i < s.length(); ++i)
//                 {
//                     // std::cout << cnt[i] << " ";
//                     if(next[i] != 0)
//                     {
//                         cnt[next[i] - 1] -= cnt[i];
//                     }
//                 }
//                 // std::cout << "\n";
//                 for(size_t i = 0; i < s.length(); ++i)
//                 {
//                     // std::cout << cnt[i] << " ";
//                     ans += ((((static_cast<unsigned long long>(i + 1))
//                               * static_cast<unsigned long long>(i + 1))
//                              % ANS_MOD)
//                             * cnt[i])
//                            % ANS_MOD;
//                     ans %= ANS_MOD;
//                     // sum += cnt[i];
//                 }
//                 // std::cout << "\n";
//                 // std::cout << "\n";
//                 // for(size_t i = 0; i < s.length(); ++i)
//                 // {
//                 // std::cout << next[i] << " ";
//                 // }
//                 // std::cout << "\n";
 
//                 // std::cout << curHash << std::endl;
//             }
//             std::cout << ans << std::endl;
//             // std::cout << "sum: " << sum << std::endl;
//         }
//     }
// }






#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6+100;
const ll hasi=19270813;
const ll mod=998244353;
ll ans;
map <unsigned long long,int> mp;
string s[maxn];
ll nxt[maxn];
ll res[maxn];
 
inline void kmp(int x){
    nxt[0]=0;
        for(int i=1,j=0;i<s[x].length();i++){
        while(s[x][i]!=s[x][j]&&j) j=nxt[j-1];
        if(s[x][i]==s[x][j]) j++;
        nxt[i]=j;
     }
}
 
int main(){
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i];
        unsigned long long x=0,tmp=1;
        for (int j=s[i].length()-1;j>=0;j--){
            x+=tmp*(s[i][j]-'a'+1);
            tmp*=hasi;
            mp[x]++;
        }
    }
    for (int i=1;i<=n;i++){
        unsigned long long x=0,tmp=1;
        for (int j=0;j<s[i].length();j++){
            x=x*hasi+(s[i][j]-'a'+1);
            res[j]=mp[x];
        }
        kmp(i);
        for (int j=0;j<s[i].length();j++){
            if (nxt[j]) res[nxt[j]-1]=res[nxt[j]-1]-res[j];
        }
        for (int j=0;j<s[i].length();j++)
        ans=(ans+res[j]%mod*(j+1)%mod*(j+1)%mod)%mod;
    }
    cout<<ans<<endl;
}











#include<cstdio>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<vector>
#define ll long long
using namespace std;
#define ull unsigned long long
const int MOD = 998244353;
ll mod = 19260817;
ll tot;
int nex[1000005];
int n;
map<ll, ull> mp;
string s[100005];
int res[1000005];
 
void makenext(string &s){
    nex[0] = 0;
    for (int i = 1, j = 0; i < s.length(); i++) {
        while (s[i] != s[j] && j) j = nex[j - 1];
        if (s[i] == s[j]) j++;
        nex[i] = j;
    }
}
 
int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        int len = s[i].length();
        ull ans = 0;
        ull power = mod;
        for (int k = len - 1; k >= 0; k--) {
            ans += power * (s[i][k] - 'a' + 1);
            power *= mod;
            mp[ans]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        makenext(s[i]);
        int len = s[i].length();
        for (int k = 0; k < len; k++)
            res[k] = 0;
        ull ans = 0;
        ull power = mod;
        for (int k = 0; k < len; k++) {
            ans += (s[i][k] - 'a' + 1);
            ans *= mod;
            res[k] = mp[ans];
        }
        for (int k = 0; k < len; k++) {
            if (nex[k]) {
                res[nex[k] - 1] -= res[k];
            }
        }
        for (int k = 0; k < len; k++) {
            tot += (ll)(k + 1) * (k + 1) * res[k];
            tot %= MOD;
        }
    }
    cout << tot;
}