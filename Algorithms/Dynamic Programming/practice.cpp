#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];

// 01 . Define state
int trib(int n)
{
    if (n <= 3)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    // 02. Recur. Eqn for sub problems
    return dp[n] = trib(n - 1) + trib(n - 2) + trib(n - 3);
}

int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << trib(n) << endl;
    return 0;
}