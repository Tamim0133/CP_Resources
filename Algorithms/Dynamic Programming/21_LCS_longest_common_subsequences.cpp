/*
Pseudocode
f(ind1, ind2)
    if(ind1 < 0 or ind2 < 0) return 0

    if(s1[ind1] == s2[ind2]) return 1 + f(ind1 -1 , ind2 - 1)
    else
    return 0 + max(f(ind1 , ind2 - 1) , f(ind1 -1 , ind2))

*/
#include <bits/stdc++.h>
using namespace std;

int f(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 or ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + f(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        return dp[ind1][ind2] = 0 + max(f(s1, s2, ind1, ind2 - 1, dp), f(s1, s2, ind1, ind2 - 1, dp));
}

int lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(s1, s2, n - 1, m - 1, dp);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << lcs(s1, s2) << endl;
}

// acd ced
// o/p : 2
// T.C : O(m * n)

// Tabulation Code

/*
#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2) {

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }

    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }

    return dp[n][m];
}

int main() {

  string s1= "acd";
  string s2= "ced";

  cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2);
}


*/