#include <bits/stdc++.h>
using namespace std;
const int MAXN = 26;

int main(void)
{
    int n;
    int num[MAXN][MAXN];
    while (scanf("%d", &n) != EOF)
    {
        int cnt = 1;
        int x = 0, y = n - 1;
        memset(num, 0, sizeof(num));
        num[x][y] = 1;
        while (cnt < n * n)
        {
            while (x + 1 < n && num[x + 1][y] == 0)
            {
                x++;
                cnt++;
                num[x][y] = cnt;
            }
            while (y - 1 >= 0 && num[x][y - 1] == 0)
            {
                y--;
                cnt++;
                num[x][y] = cnt;
            }
            while (x - 1 >= 0 && num[x - 1][y] == 0)
            {
                x--;
                cnt++;
                num[x][y] = cnt;
            }
            while (y + 1 < n && num[x][y + 1] == 0)
            {
                y++;
                cnt++;
                num[x][y] = cnt;
            }
        }
        for (x = 0; x < n; x++)
        {
            for (y = 0; y < n; y++)
            {
                cout << num[x][y];
                if (y < n - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}