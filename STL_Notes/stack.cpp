#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    Stacks are a type of container adaptors with
     LIFO(Last In First Out)
      type of working, where a new element is added at one end (top) and an element is removed from that end only. */

    /*
    >> empty() – Returns whether the stack is empty – Time Complexity : O(1)

    >> size() – Returns the size of the stack – Time Complexity : O(1)

    >> top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)

    >> push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)

    >> pop() – Deletes the top most element of the stack – Time Complexity : O(1)

    */

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl; // 4

    /*
        Direct কোন ডাটা বের করা যায় না ,
        clear() ফাংশন নাইঃ
        iterator কাজ করে না ।

        খালি আছে pop();
    */
    st.pop(); // সবার উপরএর ইলিমেন্ট ডীলেট করে

    st.top(); // 3

    // Stack প্রিন্ট করার জন্য ঃ

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    //     Problem
    // A bracket is considered to be any one of the following characters: ( , ) , { , } , [ , or ] .
    // Two brackets are considered to be a matched pair if the an opening bracket (i.e., ( , [ , or { ) occurs to the left of a closing bracket (i.e., ) , ] , or } ) of the exact same type . There are three types of matched pairs of brackets: [] , {} , and () .

    //                                         A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, ( , and the pair of parentheses encloses a single, unbalanced closing square bracket, ] .
    // By this logic, we say a sequence of brackets is balanced if the following conditions are met:
    // 1) It contains no unmatched brackets.
    // 2) The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
    // Given n strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES . Otherwise, return NO .

    // Input Format:
    // The first line contains a single integer n, the number of strings.
    // Each of the next n lines contains a single string s, a sequence of brackets.

    // Output Format:
    // For each string, return YES or NO .
    // Constraints:

    // 1 <=  n <= 103

    // 1 < |s| <= 103      , where |s| is the length of the sequence.

    // All chracters in the sequences ∈ { {, }, (, ), [, ] }.

    // Sample Input:
    // 3

    // {
    // [()]}
    // {[(])}
    // {{[[(())]]}}

    // Sample Output:
    // YES
    // NO
    // YES
    // Explanation:
    // 1. The string {[()]} meets both criteria for being a balanced string, so we print YES on a new line.
    // 2. The string {[(])} is not balanced because the brackets enclosed by the matched pair { and } are
    // not balanced: [(]) .
    // 3. The string {{[[(())]]}} meets both criteria for being a balanced string, so we print YES on a new line.

    // Sample Input
    // 6
    // }][}}(}][))]
    // [](){()}
    // ()
    // ({}([][]))[]()
    // {)[](}]}]}))}(())(
    // ([[)
    // Sample Output
    // NO
    // YES
    // YES
    // YES
    // NO
    // NO

    // #include <bits/stdc++.h>
    //     using namespace std;

    //     bool isBalanced(char c1, char c2) { return ((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']')); }

    //     int main()
    //     {
    //         int n;
    //         cin >> n;

    //         while (n--)
    //         {
    //             stack<char> st;

    //             string s;
    //             cin >> s;

    //             bool done = 1;

    //             for (auto i : s)
    //             {
    //                 if (i == '(' || i == '{' || i == '[')
    //                     st.push(i);

    //                 else
    //                 {
    //                     if (st.empty())
    //                     {
    //                         done = 0;
    //                         break;
    //                     }
    //                     else
    //                     {
    //                         if (isBalanced(st.top(), i))
    //                         {
    //                             st.pop();
    //                         }
    //                         else
    //                         {
    //                             done = 0;
    //                             break;
    //                         }
    //                     }
    //                 }
    //             }
    //             if (!st.empty())
    //                 done = 0;
    //             if (done)
    //                 cout << "YES\n";
    //             else
    //                 cout << "NO\n";
    //         }

    //         return 0;
    //     }

    // find Minimum from the stack
    // #include <bits/stdc++.h>
    // using namespace std;

    // int main()
    // {
    //     stack<int> st;

    //     st.push(1);
    //     st.push(2);
    //     st.push(3);
    //     st.push(1);
    //     st.push(0);

    //     int min = INT_MAX;

    //     while (!st.empty())
    //     {
    //         if (st.top() < min)
    //             min = st.top();

    //         st.pop();
    //     }

    //     cout << min << endl; // 0

    //     return 0;
    // }

    /*----------------------------------
              Question : 02
--------------------------------------*/
    /*

    682. Baseball Game
    Easy
    2K
    1.7K
    Companies
    You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

    You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

    An integer x.
    Record a new score of x.
    '+'.
    Record a new score that is the sum of the previous two scores.
    'D'.
    Record a new score that is the double of the previous score.
    'C'.
    Invalidate the previous score, removing it from the record.
    Return the sum of all the scores on the record after applying all the operations.

    The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.



    Example 1:

    Input: ops = ["5","2","C","D","+"]
    Output: 30
    Explanation:
    "5" - Add 5 to the record, record is now [5].
    "2" - Add 2 to the record, record is now [5, 2].
    "C" - Invalidate and remove the previous score, record is now [5].
    "D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
    "+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
    The total sum is 5 + 10 + 15 = 30.
    Example 2:

    Input: ops = ["5","-2","4","C","D","9","+","+"]
    Output: 27
    Explanation:
    "5" - Add 5 to the record, record is now [5].
    "-2" - Add -2 to the record, record is now [5, -2].
    "4" - Add 4 to the record, record is now [5, -2, 4].
    "C" - Invalidate and remove the previous score, record is now [5, -2].
    "D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
    "9" - Add 9 to the record, record is now [5, -2, -4, 9].
    "+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
    "+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
    The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
    Example 3:

    Input: ops = ["1","C"]
    Output: 0
    Explanation:
    "1" - Add 1 to the record, record is now [1].
    "C" - Invalidate and remove the previous score, record is now [].
    Since the record is empty, the total sum is 0.


    Constraints:

    1 <= operations.length <= 1000
    operations[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
    For operation "+", there will always be at least two previous scores on the record.
    For operations "C" and "D", there will always be at least one previous score on the record.
    */

    // এই প্রশ্ন খুব সহজে Stack দিয়ে করা যায় ।
    // কারণ প্রতিবার এ আমাকে last element নিয়ে কাজ করতে হচ্ছে ।

    /*
    class Solution {
    public:
        int calPoints(vector<string>& ops) {
            stack<int> st;

            for ( auto u : ops ) {

                if ( u.size() > 1 ) {
                    st.push ( stoi ( u ) );
                }
                else if ( isdigit ( u[0] ) ) {
                    st.push ( u[0] - '0' );
                }
                else if ( u[0] == '+' ) {
                    int a1 = -1, a2 = -1;

                    if ( !st.empty() ) {
                        a1 = st.top();
                        st.pop();
                    }

                    if ( !st.empty() ) {
                        a2 = st.top();
                        st.pop();
                    }

                    if ( a2 != -1 ) {
                        st.push ( a2 );
                        st.push ( a1 );
                        st.push ( a1+a2 );
                    }

                    else if ( a1 != -1 ) {
                        st.push ( a1 );
                    }
                }
                else if ( u[0] == 'D' ) {
                    if ( !st.empty() ) {
                        st.push ( 2 * st.top() );
                    }
                }
                else {
                    if ( !st.empty() ) st.pop();
                }
            }

            long long ans = 0;

            while ( !st.empty() ) {
                ans += st.top();
                st.pop();
            }

            return ans;
        }
    };
    */
    /*----------------------------------
              Question : 02
--------------------------------------*/
    /*
    1047. Remove All Adjacent Duplicates In String
    Easy
    5.3K
    206
    Companies
    You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

    We repeatedly make duplicate removals on s until we no longer can.

    Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.



    Example 1:

    Input: s = "abbaca"
    Output: "ca"
    Explanation:
    For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
    Example 2:

    Input: s = "azxxzy"
    Output: "ay"


    Constraints:

    1 <= s.length <= 105
    s consists of lowercase English letters.
    */
    /*
    class Solution {
    public:
        string removeDuplicates(string s) {
            stack <char> st;

            for ( auto u : s ) {
                if ( !st.empty() ) {
                    if ( !st.empty() && st.top() == u ) st.pop();
                    else st.push(u);
                }
                else st.push(u);
            }

            s.clear();
            while (!st.empty()) {
                s += st.top();
                st.pop();
            }

            reverse ( s.begin(), s.end() );
            return s;

        }
    };
    */
    /*----------------------------------
             Question : 03
--------------------------------------*/

    /*
    1047. Remove All Adjacent Duplicates In String
    Easy
    5.3K
    206
    Companies
    You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

    We repeatedly make duplicate removals on s until we no longer can.

    Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.



    Example 1:

    Input: s = "abbaca"
    Output: "ca"
    Explanation:
    For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
    Example 2:

    Input: s = "azxxzy"
    Output: "ay"


    Constraints:

    1 <= s.length <= 105
    s consists of lowercase English letters.
    */
    // class Solution
    // {
    // public:
    //     string removeDuplicates(string s)
    //     {
    //         stack<char> st;

    //         for (auto i : s)
    //         {

    //             if (st.empty() == 1 || st.top() != i)
    //             {
    //                 st.push(i);
    //             }
    //             else if (st.top() == i)
    //             {
    //                 st.pop();
    //             }
    //         }

    //         string ans;
    //         while (!st.empty())
    //         {
    //             ans += st.top();
    //             st.pop();
    //         }

    //         reverse(ans.begin(), ans.end());

    //         return ans;
    //     }
    // };
    return 0;
}