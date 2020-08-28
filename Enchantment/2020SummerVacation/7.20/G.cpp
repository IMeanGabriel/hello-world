#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

const int N = 25;

int n, ans;
bool g[N][N];
int col[N], dg[N], udg[N]; // 分别表示每列、正对角线、副对角线

void init(int a, int b) // 预处理国王对应的9个坐标
{
    for (int i = -1; i <= 1; i ++ )
        for (int j = -1; j <= 1; j ++ )
            g[a + i][b + j] = true;
}

void dfs(int u) // 搜索到第u行
{
    if (u == n + 1)
    {
        ans ++ ;
        return ;
    }
    for (int i = 1; i <= n; i ++ ) // 枚举每一列是否选取
    {
        if (!col[i] && !dg[i - u + n] && !udg[u + i] && !g[u][i]) // 如果u行i列可以放的话
        {
            g[u][i] = col[i] = dg[i - u + n] = udg[u + i] = true;
            dfs(u + 1); // 搜下一行
            g[u][i] = col[i] = dg[i - u + n] = udg[u + i] = false; // 恢复现场
        }
    }
}

int main()
{
    int a, b;
    cin >> n >> a >> b;
    init(a, b);
    dfs(1); // 从第一行开始搜索
    cout << ans << endl;
    return 0;
}