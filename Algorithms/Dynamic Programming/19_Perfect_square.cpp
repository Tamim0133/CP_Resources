// class Solution
// {
// public:
//     int f(int i, int tar, vector<int> &a, vector<vector<int>> &dp)
//     {
//         if (i < 0 and tar != 0)
//             return INT_MAX;
//         if (tar == 0)
//             return 0;

//         if (dp[i][tar] != -1)
//             return dp[i][tar];

//         int not_pick = f(i - 1, tar, a, dp);
//         int pick = 1e9;
//         if (a[i] <= tar)
//             pick = f(i, tar - a[i], a, dp) + 1;

//         if (i >= 0)
//             return dp[i][tar] = min(pick, not_pick);
//         else
//             return min(pick, not_pick);
//     }
//     int numSquares(int n)
//     {
//         vector<int> a;
//         for (int i = 1; i * i <= n; i++)
//         {
//             a.push_back(i * i);
//         }
//         vector<vector<int>> dp(a.size(), vector<int>(n + 1, -1));

//         return f(a.size() - 1, n, a, dp);
//     }
// };
