/*
        Time Limit: 2 sec / Memory Limit: 1024 MB


        Problem Statement
        There are "N" stones, numbered 1,2,…,N.
        For each i (1≤i≤N), the height of Stone i is hi  .

        There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

        If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of∣hi​−hj​ ∣ is incurred,
        where j is the stone to land on.
        Find the minimum possible total cost incurred before the frog reaches Stone
        N.

        Constraints
        All values in input are integers.
        2≤N≤10^5
        1≤hi≤10^4


        Output
        Print the minimum possible total cost incurred.

        Sample Input 1
        4
        10 30 40 20
        Sample Output 1
        30
        If we follow the path
        1 → 2 → 4, the total cost incurred would be
        ∣10−30∣+∣30−20∣=30.

        Sample Input 2
        2
        10 10
        Sample Output 2
        0
        If we follow the path
        1 → 2, the total cost incurred would be
        ∣10−10∣=0.

        Sample Input 3
        6
        30 10 60 10 60 50
        Sample Output 3
        40
        If we follow the path
        1 →  3 →  5 →  6, the total cost incurred would be
        ∣30−60∣+∣60−60∣+∣60−50∣=40.



*/

// problem link - https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
/*
- state: stone(n) -> cost of reaching n-th stone from 1st stone
- recurrance: stone(n) = min(
                            stone(n-1) + abs( h[n] - h[n-1])
                            stone(n-2) + abs( h[n] - h[n-2])
                        )
- base case: stone(1) = 0
*/
int h[N];
int dp[N];

int stone(int n)
{
    // 1. base case
    if (n == 1)
    {
        return 0;
    }

    // 2. check if answer already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // 3. calculate answer from subproblems
    int ans1 = stone(n - 1) + abs(h[n] - h[n - 1]);

    // corner case
    if (n == 2)
    {
        dp[n] = ans1;
        return ans1;
    }

    int ans2 = stone(n - 2) + abs(h[n] - h[n - 2]);
    int ans = min(ans1, ans2);

    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << stone(n) << endl;
    return 0;
}
/*

Tabulation / Iterative Solution :

#include <bits/stdc++.h>
    using namespace std;
const int N = 1e5 + 5;

// - state: stone(n) -> cost of reaching n-th stone from 1st stone
// - recurrance: stone(n) = min(
//                             stone(n-1) + abs( h[n] - h[n-1])
//                             stone(n-2) + abs( h[n] - h[n-2])
//                         )
// - base case: stone(1) = 0

int h[N];
int dp[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> h[i];
    }

    // 1. handle base case
    dp[1] = 0;

    // 2. loop through the states
    for(int i = 2 ; i <= n ; i++) {
        // 2.1. solve from smaller sub-problems

        int ans1 = dp[i-1] + abs(h[i] - h[i-1]);

        // corner case
        if(i == 2) {
            dp[i] = ans1;
            continue;
        }

        int ans2 = dp[i-2] + abs(h[i] - h[i-2]);
        dp[i] = min(ans1, ans2);
    }

    cout << dp[n] << endl;
    return 0;
}


*/