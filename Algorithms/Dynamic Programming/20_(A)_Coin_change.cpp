// We have a infinite supply of coins we need to tell in max how many ways can we make a coin change
#include <bits/stdc++.h>
using namespace std;

long f(vector<int> &a, int ind, int T, vector<vector<int>> &dp)
{
    if (ind == 0)
        return (T % a[0] == 0);
    if (dp[ind][T] != -1)
        return dp[ind][T];

    long notTaken = f(a, ind - 1, T, dp);
    long taken = 0;

    if (a[ind] <= T)
    {
        taken = f(a, ind, T - a[ind], dp);
    }

    return dp[ind][T] = taken + notTaken;
}

int main()
{
    // vector<int> a = {1, 2, 3};
    // int tar = 4;
    // result = 4

    int n;
    cin >> n;
    vector<int> a(n + 1);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int tar;
    cin >> tar;

    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

    cout << f(a, n - 1, tar, dp) << endl;

    return 0;
}