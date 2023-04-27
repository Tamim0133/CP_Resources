#include <bits/stdc++.h>

using namespace std;

long long solveUtil(long long ind, vector<long long> &arr, vector<long long> &dp)
{

    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 1)
        return arr[ind];
    if (ind <= 0)
        return 0;

    long long pick = arr[ind] * ind + solveUtil(ind - 2, arr, dp);
    long long nonPick = 0 + solveUtil(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}

long long solve(long long n, long long k, vector<long long> &arr)
{
    vector<long long> dp(k + 3, -1);
    return solveUtil(k, arr, dp);
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(1e5 + 5, 0);
    long long k = INT_MIN, x;
    for (long long i = 0; i < n; i++)
    {
        cin >> x;
        k = max(k, x);
        arr[x]++;
    }
    cout << solve(n, k, arr) << endl;
}