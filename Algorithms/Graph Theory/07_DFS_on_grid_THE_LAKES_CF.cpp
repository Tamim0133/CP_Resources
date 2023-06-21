// https://codeforces.com/contest/1829/problem/E
/*
5 5
1 1 1 1 1
1 0 0 0 1
1 0 5 0 1
1 0 0 0 1
1 1 1 1 1

16

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const int N = 1e3 + 5;
int n, m;
bool vis[N][N] = {0};
int a[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y)
{
    vis[x][y] = true;

    int ans = a[x][y];

    for (int i = 0; i < 4; i++)
    {
        int dx_, dy_;

        dx_ = x + dx[i];
        dy_ = y + dy[i];

        if (dx_ >= 0 && dx_ <= n - 1 && dy_ >= 0 && dy_ <= m - 1 && !vis[dx_][dy_] && a[dx_][dy_] != 0)
        {
            ans += dfs(dx_, dy_);
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] and a[i][j] != 0)
            {
                ans = max(ans, dfs(i, j));
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}