#include <bits/stdc++.h>
using namespace std;

const int N = 3000;

int dp[N + 1][N + 1];

string s1, s2;

int lcs(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == 0 || j == 0)
        return dp[i][j] = 0; // base case : jodi "0" te chole ashe tahole tokhon amra check kora bad diye di

    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 1 + lcs(i - 1, j - 1); // jodi last idx mile jay tahole last idx skip kore check kora

    return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1)); // else case : jodi last idx na mile tokhon duitar e akta kora bad diye milanir try kora
}

string lcs_print_kora(int i, int j)
{
    if (i == 0 || j == 0) // jodi "0" te chole ashe tokhon amra kichu print korbo na
        return "";

    if (s1[i - 1] == s2[j - 1]) // jodi last index mile jay tokhon amra last ta print kore baki gular jonno khoj korte thakbo
        return lcs_print_kora(i - 1, j - 1) + s1[i - 1];

    if (dp[i - 1][j] > dp[i][j - 1]) // Ager max case er moto amra khujtechi jeta the beshi paoya jay oita diya kora
        return lcs_print_kora(i - 1, j);

    else
        return lcs_print_kora(i, j - 1);
}

int main()
{
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    int len = lcs(s1.size(), s2.size());
    string ans = lcs_print_kora(s1.size(), s2.size());
    cout << ans << endl;
    return 0;
}
