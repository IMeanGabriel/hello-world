#include <bits/stdc++.h>
using namespace std;
    bool vis[50][3] = {0};
    int a2[50] = {0};
    int a1[50] = {0};
    int n, k = 0;
    int ans = 0;
void solve(int x)
{
    if (x == k)
        ans++;
    else
    {
        int now = a1[x];
        for (int i = 0; i < 8; i++)
        {
            if (!vis[i][0] && !vis[now - i + 8][1] && !vis[now + i][2])
            {
                a2[now] = i;
                vis[i][0] = vis[now - i + 8][1] = vis[now + i][2] = 1;
                solve(x + 1);
                vis[i][0] = vis[now - i + 8][1] = vis[now + i][2] = 0;
            }
        }
    }
}

int main(void)
{

    int x, i, j;
    for (int i = 0; i < 8; i++)
    {
        bool flg = true;
        for (int j = 0; j < 8; j++)
        {
            cin >> x;
            if (x == 1)
            { 
                flg = false;
                vis[j][0] = vis[i - j + 8][1] = vis[i + j][2] = 1;
            }
        }
        if (flg==true)
        {
            a1[k++] = i;
        }
    }
    solve(0);
    cout << ans;
    return 0;
}