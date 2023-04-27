/*
You are given an integer n.You can perform any of the following operations on  it as many times you want -
Subtract 1 from it
If it is divisible by 2 divide by 2
If it is divisible by 3 divide by 3

        Find the minimum number of operations to make n=1

*/

#include <bits/stdc++.h>
using namespace std;

// int b = INT_MAX;
// int c = INT_MAX;
// int mini(int a, int b, int c)
// {
//     if (a < b and a < c)
//         return a;
//     else if (b < c)
//         return b;
//     else
//         return c;
// }

int f(int n, vector<int> dp)
{
    if (n == 1)
        return 0;
    // if (n == 2)
    //     return 2;
    // if (n == 3)
    //     return 2;

    if (dp[n] != -1)
        return dp[n];

    int a = f(n - 1, dp) + 1;

    if (n % 2 == 0)
        a = min(a, f(n / 2, dp) + 1);
    if (n % 3 == 0)
        a = min(a, f(n / 3, dp) + 1);

    return dp[n] = a;
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 3, -1);

    cout << f(n, dp) << endl;

    return 0;
}

/*
Tabulation :

#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> dp)
{
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 3, -1);

    cout << f(n, dp) << endl;

    return 0;
}







*/