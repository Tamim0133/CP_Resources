// https://cses.fi/problemset/result/6009990/
#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &a)
{
    if (i < 0 or j < 0)
        return 0;
    if (a[i][j] == -1)
        return 0;
    if (i == 0 and j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = f(i - 1, j, dp, a);
    int left = f(i, j - 1, dp, a);

    return dp[i][j] = (up + left) % mod;
}

int main()
{
    int h, w;

    int n;
    cin >> n;

    h = w = n;

    vector<vector<int>> a(h, vector<int>(w, 0));
    char c;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> c;
            if (c == '*')
                a[i][j] = -1;
        }
    }

    vector<vector<int>> dp(h, vector<int>(w, -1));

    cout << f(h - 1, w - 1, dp, a) << endl;

    return 0;
}