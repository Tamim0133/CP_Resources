/*----------------------------
------

    01 : Declaration
    02 : .clear(), .empty (), .insert()
    03 : .count()
    04 : .erase()
    05 : Set of Pairs
    06 : others

                    -------------
-------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*--------------------------------------
          01 : Declration
  ---------------------------------------*/
    /// Declaration of set of integers
    set<int> s = {1, 1, 2, 1, 3};

    /// Printing size and elements
    cout << s.size() << endl;
    for (auto u : s)
        cout << u << " "; /// 1 2 3
    cout << endl;

    /*
        >> set এর মদ্ধে element
                            (01) Sorted
                            (02) Unique

        সব অপারেশনের কমপ্লেক্সিটি O(logn)
    */

    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << " "; /// 1 2 3
    cout << endl;

    /*--------------------------------------
        02 : .clear() , .empty() , .inset()
    ---------------------------------------*/
    // Complexity : O(logn)
    s.clear();
    cout << s.empty() << endl; /// 1

    /// inserting in set
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.insert(3);

    cout << s.size() << endl; /// 3
    for (auto u : s)
        cout << u << " "; /// 1 2 3
    cout << endl;
    /*--------------------------------------
                  03 : .count()
      ---------------------------------------*/
    /// কোন একটা এলিমেন্ট আছে কিনা । থাকলে always 1 ই print করে ।
    cout << s.count(2) << endl; /// 1 ; ২ একবার ই আছে । O(logn)
    cout << s.count(4) << endl; /// 0 ; 4 নাই

    /*--------------------------------------
                   04 : .erase()
      ---------------------------------------*/
    /// সবার সামনে এলিমেন্ট টা কি ?
    cout << *s.begin() << endl; /// 1

    /// সবার শেষের এলিমেন্ট টা কি ?
    cout << *(--s.end()) << endl; /// 3
    cout << *s.rbegin() << endl;  /// 3

    /// Erase করার জন্য

    s = {1, 2, 3, 4, 5, 6};

    s.erase(2);
    cout << s.size() << endl; /// 5

    for (auto u : s)
        cout << u << " "; /// 1 3 4 5 6
    cout << endl;

    s.erase(10);
    cout << s.size() << endl; /// 5

    for (auto u : s)
        cout << u << " "; /// 1 3 4 5 6
    cout << endl;

    // শুরু থেকে প্রথম ইলিমেন্ট ডিলেট করা

    s = {1, 2, 3, 4, 5, 6};

    s.erase(s.begin());
    cout << s.size() << endl; /// 5
    for (auto u : s)
        cout << u << " "; /// 2 3 4 5 6
    cout << endl;

    // শেষ  থেকে প্রথম ইলিমেন্ট ডিলেট করা

    s = {1, 2, 3, 4, 5, 6};

    s.erase(--s.end());
    cout << s.size() << endl; /// 5
    for (auto u : s)
        cout << u << " "; /// 1 2 3 4 5
    cout << endl;
    /*----------------------------------------
                05 : Set of Pair
    -----------------------------------------*/

    /// set of pair
    set<pair<int, int>> s1;

    s1.insert({1, 2});
    s1.insert({1, 2});
    s1.insert({4, 2});
    s1.insert({4, 3});
    s1.insert({2, 2});
    s1.insert({2, 1});

    /**

    Output :

    5
    1 2
    2 1
    2 2
    4 2
    4 3

    */

    cout << s1.size() << endl;
    for (auto u : s1)
        cout << u.first << " " << u.second << endl;

    /*----------------------------------------
              06 : Others
  -----------------------------------------*/

    /// Set of string

    set<string> s2;

    s2.insert("momo");
    s2.insert("momo");
    s2.insert("prety");
    s2.insert("prety");
    s2.insert("shahriar");
    s2.insert("nobel");
    s2.insert("sharif");
    s2.insert("proma");

    cout << s2.size() << endl;
    for (auto u : s2)
        cout << u << endl;

    /**

    Output :

    6
    momo
    nobel
    prety
    proma
    shahriar
    sharif

    */

    /// set in discanding order
    set<int, greater<int>> s3 = {3, 4, 1, 2};
    for (auto u : s3)
        cout << u << " "; /// 4 3 2 1
    cout << endl;

    set<string, greater<string>> s4;

    s4.insert("momo");
    s4.insert("momo");
    s4.insert("prety");
    s4.insert("prety");
    s4.insert("shahriar");
    s4.insert("nobel");
    s4.insert("sharif");
    s4.insert("proma");

    cout << s4.size() << endl;
    for (auto u : s4)
        cout << u << endl;

    /**
    Output :

    6
    sharif
    shahriar
    proma
    prety
    nobel
    momo

    */

    set<pair<int, int>, greater<pair<int, int>>> s5;

    s5.insert({1, 2});
    s5.insert({1, 2});
    s5.insert({4, 2});
    s5.insert({4, 3});
    s5.insert({2, 2});
    s5.insert({2, 1});

    cout << s5.size() << endl;
    for (auto u : s5)
        cout << u.first << " " << u.second << endl;

    /**

    Output :
    5
    4 3
    4 2
    2 2
    2 1
    1 2

    */

    /*-------------------------------
             Question : 01
     ----------------------------*/
    /*
    you will be given  queries. Each query is of one of the following three types:

    : Add an element  to the set.
    : Delete an element  from the set. (If the number  is not present in the set, then do nothing).
    : If the number  is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

    Input Format

    The first line of the input contains  where  is the number of queries. The next  lines contain  query each. Each query consists of two integers  and  where  is the type of the query and  is an integer.

    Constraints




    Output Format

    For queries of type  print "Yes"(without quotes) if the number  is present in the set and if the number is not present, then print "No"(without quotes).
    Each query of type  should be printed in a new line.

    Sample Input

    8
    1 9
    1 6
    1 10
    1 4
    3 6
    3 14
    2 6
    3 6
    Sample Output

    Yes
    No
    No*/

    // set<int> s;
    // int q;
    // cin >> q;
    // while(q--)
    // {
    //     int y,x;
    //     cin >> y>>x;

    //     if(y==1)
    //     {
    //         s.insert(x);
    //     }
    //     else if (y==2)
    //     {
    //         s.erase(x);
    //     }
    //     else if(y == 3)
    //     {
    //         if(s.count(x))
    //         cout << "Yes\n";
    //         else
    //         cout << "No\n";
    //     }
    // }

    /*-------------------------------
          Question : 02
  ----------------------------*/
    /*
        A. I Wanna Be the Guy

    time limit per test1 second
    memory limit per test256 megabytes
    inputstandard input
    outputstandard output
    There is a game called "I Wanna Be the Guy", consisting of n levels. Little X and his friend Little Y are addicted to the game. Each of them wants to pass the whole game.

    Little X can pass only p levels of the game. And Little Y can pass only q levels of the game. You are given the indices of levels Little X can pass and the indices of levels Little Y can pass. Will Little X and Little Y pass the whole game, if they cooperate each other?

    Input
    The first line contains a single integer n (1 ≤  n ≤ 100).

    The next line contains an integer p (0 ≤ p ≤ n) at first, then follows p distinct integers a1, a2, ..., ap (1 ≤ ai ≤ n). These integers denote the indices of levels Little X can pass. The next line contains the levels Little Y can pass in the same format. It's assumed that levels are numbered from 1 to n.

    Output
    If they can pass all the levels, print "I become the guy.". If it's impossible, print "Oh, my keyboard!" (without the quotes).

    Examples
    inputCopy
    4
    3 1 2 3
    2 2 4
    outputCopy
    I become the guy.
    inputCopy
    4
    3 1 2 3
    2 2 3
    outputCopy
    Oh, my keyboard!
    Note
    In the first sample, Little X can pass levels [1 2 3], and Little Y can pass level [2 4], so they can pass all the levels both.

  In the second sample, no one can pass level 4.
    */
    // #include <bits/stdc++.h>
    //     using namespace std;

    //     int main()
    //     {
    //         int n;
    //         cin >> n;

    //         set<int> levels;

    //         for (int i = 1; i <= n; i++)
    //             levels.insert(i);

    //         int x;
    //         cin >> x;
    //         while (x--)
    //         {
    //             int k;
    //             cin >> k;
    //             levels.erase(k);
    //         }

    //         int y;
    //         cin >> y;
    //         while (y--)
    //         {
    //             int l;
    //             cin >> l;
    //             levels.erase(l);
    //         }
    //         if (levels.empty())
    //             cout << "I become the guy." << endl;
    //         else
    //             cout << "Oh, my keyboard!" << endl;
    //         return 0;
    //     }

    /*-------------------------------
         Question : 03
 ----------------------------*/

    /*
    A. Second Order Statistics
    time limit per test2 seconds
    memory limit per test256 megabytes
    inputstandard input
    outputstandard output
    Once Bob needed to find the second order statistics of a sequence of integer numbers. Lets choose each number from the sequence exactly once and sort them. The value on the second position is the second order statistics of the given sequence. In other words it is the smallest element strictly greater than the minimum. Help Bob solve this problem.

    Input
    The first input line contains integer n (1 ≤ n ≤ 100) — amount of numbers in the sequence. The second line contains n space-separated integer numbers — elements of the sequence. These numbers don't exceed 100 in absolute value.

    Output
    If the given sequence has the second order statistics, output this order statistics, otherwise output NO.

    Examples
    inputCopy
    4
    1 2 2 -4
    outputCopy
    1
    inputCopy
    5
    1 2 3 1 1
    outputCopy
2
    */

    // #include <bits/stdc++.h>
    // using namespace std;

    // int main()
    // {
    //     int n;
    //     cin >> n;

    //     set<int> s;

    //     while (n--)
    //     {
    //         int k;
    //         cin >> k;
    //         s.insert(k);
    //     }
    //     if (s.size() > 1)
    //         cout << *(++s.begin());
    //     else
    //         cout << "NO" << endl;
    //     return 0;
    // }

    /*-------------------------------
        Question : 04
----------------------------*/
    /*
        Implement different operations on a set s .

    Input:
    The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of input contains an integer Q denoting the no of queries . Then in the next line are Q space separated queries .
    A query can be of four types
    1. a x (inserts an element x to the set s)
    2. b (prints the contents of the set s)
    3. c x (erases an element x from the set s)
    4. d x (prints 1 if the element x is present in the set else print -1)
    5. e (prints the size of the set s)

    Output:
    The output for each test case will  be space separated integers denoting the results of each query .

    Constraints:
    1<=T<=100
    1<=Q<=100

    Example:

    Input
    2
    6
    a 1 a 2 a 3 b c 2 b
    5
    a 1 a 5 e d 5 d 2

    Output
    1 2 3 1 3
    2 1 -1

    */
    /* You are required to complete below methods */

    // void insert(set<int> & s, int x)
    // {
    //     s.insert(x);
    // }

    // void print_contents(set<int> & s)
    // {
    //     for (auto i : s)
    //         cout << i << " ";
    // }

    // void erase(set<int> & s, int x)
    // {
    //     s.erase(x);
    // }

    // int find(set<int> & s, int x)
    // {
    //     if (s.count(x) == 1)
    //         return 1;
    //     else
    //         return -1;
    // }

    // int size(set<int> & s)
    // {
    //     s.size();
    // }

    /*-------------------------------
        Question : 05
----------------------------*/

    //     You are given an array A of size N. you need to insert the elements of A into a set and display the results. Also, you need to erase a given element x from the set and print "erased x" if successfully erased, else print "not found".

    // Example 1:

    // Input:
    // N = 10
    // A[] = 9 8 7 4 4 2 1 1 9 8
    // x = 1
    // Output:
    // 1 2 4 7 8 9
    // erased 1
    // 2 4 7 8 9

    // set<int> setInsert(int arr[], int n)
    // {
    //     set<int> s;

    //     for (int i = 0; i < n; i++)
    //         s.insert(arr[i]);

    //     return s;
    // }

    // void setDisplay(set<int> s)
    // {
    //     for (auto i : s)
    //         cout << i << " ";
    //     cout << endl;
    // }

    // void setErase(set<int> & s, int x)
    // {
    //     if (s.count(x))
    //     {
    //         s.erase(x);
    //         cout << "erased " << x;
    //     }

    //     else
    //         cout << "not found";

    //     cout << endl;
    // }

    /*-------------------------------
        Question : 06
----------------------------*/
    /*
        Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



    Example 1:

    Input: nums = [1,2,3,1]
    Output: true
    Example 2:

    Input: nums = [1,2,3,4]
    Output: false
    Example 3:

    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true


    Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109

    */
    // class Solution
    // {
    // public:
    //     bool containsDuplicate(vector<int> &nums)
    //     {
    //         set<int> s;

    //         for (int i = 0; i < nums.size(); i++)
    //             s.insert(nums[i]);

    //         if (s.size() < nums.size())
    //             return true;
    //         else
    //             return false;
    //     }
    // };

    return 0;
}
