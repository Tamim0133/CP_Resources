#include <bits/stdc++.h>
using namespace std;

int f(int n, int a[], int dp[], int k)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int minStep = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (n - j >= 0)
        {
            int jmp = f(n - j, a, dp, k) + abs(a[n] - a[n - j]);
            minStep = min(minStep, jmp);
        }
    }
    return dp[n] = minStep;
}

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    int a[n];
    int dp[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = -1;
    }

    cout << f(n - 1, a, dp, k) << endl;

    return 0;
}