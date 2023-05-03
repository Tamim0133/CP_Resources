/*
Part – 1: Memoizaton

As every number is equal to the sum of the previous two terms, the recurrence relation can be written as:f

        f(n)  =  f(n-1) + f(n-2)

The basic pseudo-code for the problem will be given as:

        f(n)
        {
            if(n <= 1)
            return n;
            return f(n-1) + f(n-2)

        }

                            f(5)
                            /   \
                          f(4)  f(3)
                          /  \
                        f(3)  f(2)
                        /  \
                      f(2) f(1)
                     /   \
                    f(1) f(0)


We want to compute f(2) as the second call from f(4), but in the recursive tree we had already computed f(2) once (in the first recursive call of f(3) ) Similar is the case with f(3), therefore if we somehow store these values, the first time we calculated it then we can simply find its value in constant time whenever we need it. This technique is called Memoization. Here the cases marked in yellow are called overlapping sub-problems and we need to solve them only once during the code execution.


Steps to memoize a recursive solution:

Any recursive solution to a problem can be memoized using these three steps:

01. Create a dp[n+1] array initialized to -1.

02. Whenever we want to find the answer of a particular value (say n), we first check whether the answer is already calculated using the dp array(i.e dp[n]!= -1 ). If yes, simply return the value from the dp array.

03. If not, then we are finding the answer for the given value for the first time, we will use the recursive relation as usual but before returning from the function, we will set dp[n] to the solution we get.

Time Complexity: O(N)

Reason: The overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).

Space Complexity: O(N)

Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)


*/

#include <bits/stdc++.h>

using namespace std;

int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int main()
{

    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
    return 0;
}

/*
Part 2 : Tabulation


#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n = 5;
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}


part 3 : Space Optimization



#include <bits/stdc++.h>

         using namespace std;

int main()
{

    int n = 5;

    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
    return 0;
}


*/