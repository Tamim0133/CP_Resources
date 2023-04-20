// https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
// https://leetcode.com/problems/house-robber/

// Memoization

/*
t.c : O(N)
s.c : O(N) + O(N)
*/
#include <bits/stdc++.h>

using namespace std;

int solveUtil(int ind, vector<int> &arr, vector<int> &dp)
{

    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    int pick = arr[ind] + solveUtil(ind - 2, arr, dp);
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}

int solve(int n, vector<int> &arr)
{
    vector<int> dp(n, -1);
    return solveUtil(n - 1, arr, dp);
}

int main()
{

    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    cout << solve(n, arr);
}

/*
tabulation :
t.c : O(N)
s.c : O(N)

#include <bits/stdc++.h>

using namespace std;

int solveUtil(int n, vector<int>& arr, vector<int>& dp){

    dp[0]= arr[0];

    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];

        dp[i]= max(pick, nonPick);
    }


    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n, arr, dp);
}


int main() {

  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<solve(n,arr);

}
*/