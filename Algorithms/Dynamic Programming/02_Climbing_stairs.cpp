/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

/*
    Intuition
    f(n)
    {
        if(n == 0) return 0; ০ তে কোন স্টেপ লাগে না
        n == 1 return 1; ০ থেকে ১ এ দুইটা স্টেপ লাগে
        n == 2 return 2; করনার কেস


        l = f(n-1)
        r = f(n-2)

        return l + r; ----- > Returns total number of ways
    }
*/

const int N = 1e5;
int dp[N];
class Solution
{
public:
    int climb(int n)
    {

        if (n == 0)
            return 1;
        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = climb(n - 1) + climb(n - 2);
    }

    int climbStairs(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
        }
        return climb(n);
    }
};
