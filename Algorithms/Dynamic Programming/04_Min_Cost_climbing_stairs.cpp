/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.



Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
*/

/*
আগের টার সাথে ডিফারেন্স ঃ
আমি যদি কোণ স্টেয়ার থেকে অন্য স্টেয়ার এ যাই তাহলে আমার অইটাকা দিয়ে জাওয়া লাগবে । অই টাকা নট ডিফারেন্স ।
*/
/*
#include<bits/stdc++.h>
const int N = 1e5;
int dp[N];
class Solution {
public:
    int costs (int n ,vector<int>& cost )
    {
        if(n <= 1) return cost[n]; // এইখানে একটু ক্যাচাল আছে । আমি যদি ১ এ উঠে থাকই । তাহলে আমার ১ এর টাকা দেয়া লাগবে । ০ বেজড ইন্ডেক্সিং এ ০ এর টাকা ও দেয়া লাগবে ।

        if(dp[n] != -1)
        return dp[n];

        int l =costs(n-1, cost) + cost[n]; // আমি ন-১ থেকে ন তে আসছি । তাইলে আমার কস্ট দেয়া লাগবে ন এর কস্ট ।
        int r =costs(n-2, cost) + cost[n];

        return dp[n] = min(l,r);


    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();

        for(int i = 0; i<n; i++)
        dp[i] = -1;

        return costs(n-1,cost); // এইটা লিটকোডের সমস্যা । অরা ০ বেস ইনডেক্স নিছে ।
    }
};

*/