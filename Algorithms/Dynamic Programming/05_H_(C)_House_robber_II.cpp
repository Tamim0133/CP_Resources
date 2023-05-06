// class Solution {
// public:

//     int f(int ind , vector<int> &arr, vector<int>&dp){

//         if (ind == 0)
//             return arr[ind];
//         if (ind < 0)
//             return 0;
//         if (dp[ind] != -1)
//         return dp[ind];

//         int pick = arr[ind] + f(ind - 2, arr, dp);
//         int nonPick = 0 + f(ind - 1, arr, dp);

//         return dp[ind] = max(pick, nonPick);
//     }

//     int rob(vector<int>& nums) {

//         int n = nums.size();
//         vector<int> dp1(n , -1);
//         vector<int> dp2(n , -1);

//         if(n == 1) return nums[0];

//         vector<int> temp1 , temp2;
//         for(int i = 0; i<n; i++)
//         {
//             if(i != 0) temp1.push_back(nums[i]);
//             if(i != n-1) temp2.push_back(nums[i]);
//         }

//         return max(f(temp1.size()-1,temp1,dp1),f(temp2.size()-1,temp2,dp2));
//     }
// };
