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

/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 2e9;

// - state: stone(n) -> cost of reaching n-th stone from 1st stone
// - recurrance: stone(n) = for i = 1 to  k:
//                             min(
//                                 stone(n-i) + abs(h[n] - h[n-i])
//                             )
// - base case: stone(1) = 0
// // corner case => cant jump from stones with number <= 0


int h[N], dp[N];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    // 1. base case
    dp[1] = 0;

    // 2. loop over the states
    for (int i = 2; i <= n; i++)
    {
        dp[i] = INF;

        // 2.1. calculate answer from smaller sub-problems
        for (int j = 1; j <= k; j++)
        {
            int from_stone = i - j;
            if (from_stone <= 0)
            {
                break;
            }
            int candidate_ans = dp[from_stone] + abs(h[i] - h[from_stone]);
            dp[i] = min(dp[i], candidate_ans);
        }
    }

    cout << dp[n] << endl;
    return 0;
}

*/