/*
Pseudocode :
not_take = 0 + f(ind -1 , w)
take = f(ind - 1 , W - wt[ind]) + val[ind];


base case :

if(ind == 0)
    if(wt[0] <= W)
        return val[0]
    return 0;

*/

#include <bits/stdc++.h>

using namespace std;

int knapsackUtil(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);

    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);

    return dp[ind][W] = max(notTaken, taken);
}

int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main()
{

    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;

    int n = wt.size();

    cout << "The Maximum value of items, thief can steal is " << knapsack(wt, val, n, W);
}

/*
Tabulation :

#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W){

    vector<vector<int>> dp(n,vector<int>(W+1,0));

    //Base Condition

    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }

    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){

            int notTaken = 0 + dp[ind-1][cap];

            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];

            dp[ind][cap] = max(notTaken, taken);
        }
    }

    return dp[n-1][W];
}

int main() {

  vector<int> wt = {1,2,4,5};
  vector<int> val = {5,4,8,6};
  int W=5;

  int n = wt.size();

  cout<<"The Maximum value of items, thief can steal is " <<knapsack(wt,val,n,W);
}

*/

/*
Memoization : mahir bhai er code

// problem link - https://atcoder.jp/contests/dp/tasks/dp_d

#include<bits/stdc++.h>
using namespace std;

const int N = 102;
const int M = 1e5 + 5;

long long dp[N][M];
int wt[N], val[N];

long long knapsack(int n, int cap) {
    // 1. base case
    if(n == 0) {
        return 0;
    }
    // 2. if result is already calculated for this state return it
    if(dp[n][cap] != -1) {
        return dp[n][cap];
    }


    // 3. calculate result from smaller sub-problems
    if(cap < wt[n]) {
        long long ans = knapsack(n-1, cap);
        dp[n][cap] = ans;
        return ans;
    }

    long long ans1 = val[n] + knapsack(n - 1, cap - wt[n]); // pick
    long long ans2 = knapsack(n-1, cap);  // not pick

    long long ans = max(ans1, ans2);
    dp[n][cap] = ans;

    return ans;
}

int main() {
    int n, cap;
    cin >> n >> cap;

    for(int i = 1 ; i <= n ; i++) {
        cin >> wt[i] >> val[i];
    }

    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= cap ; j++) {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, cap) << endl;
    return 0;

}


*/