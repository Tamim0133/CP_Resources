/*
                01 : Declaration
                02 : Example
                03 : Take User Input
                04 : Main Use


*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*------------------------------------
                01 : Declaration
  --------------------------------*/

    map<int, int> mpp;
    //      key , value
    // Key value pair (01 . sorted and 02. unique)

    map<string, int> mpp;
    map<string, string> mpp;

    mpp[1] = 2;
    mpp[2] = 3;

    mpp.insert({2, 4});

    for (auto i : mpp)
        cout << i.first << " " << i.second << endl;

    /*------------------------------------
            02 : Example
--------------------------------*/
    map<string, int> id;

    id["shahriar"] = 1;
    id["momo"] = 3;
    id["sharif"] = 5; // ডিলেট হয়ে যাবে , একি কি দুইবার ব্যাবহার হয় না ।
    id["sharif"] = 7;
    id["prety"] = 6;
    id["dima"] = 9;
    // এইগুলা সব assignment এর কমপ্লেক্সিটি O(logn) not O(1)

    for (auto i : id)
        cout << i.first << " " << i.second << endl;

    /*
    dima 9
    momo 3
    prety 6
    shahriar 1
    sharif 7


    lexographically sorted
    */

    /*------------------------------------
            03 : Take User Input
  --------------------------------*/
    int n;
    cin >> n;
    map<string, int> id;

    for (int i = 0; i < n; i++)
    {
        string s;
        int d;
        cin >> s >> d;
        id[s] = d;
    }

    /*------------------------------------
              04 : Main Use
    --------------------------------*/
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // 1 5 2 7 3 2 7 8

    map<int, int> m;

    for (auto i : v) // Complexity : O(nlogn)
        m[i]++;
    // ম্যাপের ভেতরে কি হিসেবে ভেক্টরে ইলিমেন্ট বসাইয়া তার ভাল্যু বারাই দিবো ।

    for (auto i : m)
        cout << i.first << " " << i.second << endl;

    /*
    1 1
    2 2
    3 1
    5 1
    7 2
    8 1
    */
    /*------------------------------------
             Question : 01
     --------------------------------*/

    /*
    i/p :

    4
    abacaba
    acaba
    abacaba
    acab

    o/p :
    OK
    OK
    abacaba1
    OK

    */

    // int n;
    // cin >> n;

    // map<string, int> cnt;

    // while ( n-- ) {
    //     string s;
    //     cin >> s;

    //     if ( cnt[s] == 0 ) cout << "OK\n";
    //     else cout << s << cnt[s] << endl;

    //     cnt[s]++;
    // }

    /*------------------------------------
               Question : 02
       --------------------------------*/

    /*
        2 2
    main 192.168.0.2
    replica 192.168.0.1
    block 192.168.0.1;
    proxy 192.168.0.2;

    output :
    block 192.168.0.1; #replica
    proxy 192.168.0.2; #main

    3 5
    google 8.8.8.8
    codeforces 212.193.33.27
    server 138.197.64.57
    redirect 138.197.64.57;
    block 8.8.8.8;
    cf 212.193.33.27;
    unblock 8.8.8.8;
    check 138.197.64.57;

    redirect 138.197.64.57; #server
    block 8.8.8.8; #google
    cf 212.193.33.27; #codeforces
    unblock 8.8.8.8; #google
    check 138.197.64.57; #server


    */

    // int n, m;
    // cin >> n >> m;

    // map<string, string> ipName;

    // for (int i = 0; i < n; i++)
    // {
    //     string name, ip;
    //     cin >> name >> ip;

    //     ipName[ip] = name;
    // }

    // while (m--)
    // {
    //     string s1, ip;
    //     cin >> s1 >> ip;

    //     ip.pop_back();
    //     cout << s1 << " " << ip << "; #" << ipName[ip] << endl;
    // }

    /*------------------------------------
                 Question : 03
         --------------------------------*/

    /*

    6
    tom
    lucius
    ginny
    harry
    ginny
    harry

    NO
    NO
    NO
    NO
    YES
    YES

    3
    a
    a
    a

    NO
    YES
    YES
    */

    // int n;
    // cin >> n;

    // map<string, bool> vis;

    // while (n--)
    // {
    //     string s;
    //     cin >> s;
    //     if (vis[s] == 1)
    //         cout << "YES\n";
    //     else
    //         cout << "NO\n";

    //     vis[s] = 1;
    // }

    /*------------------------------------
                  Question : 04
          --------------------------------*/
    /*
    2
    2 4
    1 6102
    1 6103
    2 6102
    2 6103

    2 4
    1 6102
    1 6102
    2 6102
    2 6103

    Output:
    Scenario #1: possible
    Scenario #2: impossible
    */

    // int t;
    // cin >> t;

    // for (int tc = 1; tc <= t; tc++)
    // {
    //     int n, m;
    //     cin >> n >> m;

    //     map<pair<int, int>, bool> vis;

    //     bool done = 1;
    //     while (m--)
    //     {
    //         int a, b;
    //         cin >> a >> b;

    //         if (vis[{a, b}])
    //             done = 0;
    //         vis[{a, b}] = 1;
    //     }

    //     if (done == 1)
    //         cout << "Scenario #" << tc << ": possible" << endl;
    //     else
    //         cout << "Scenario #" << tc << ": impossible" << endl;
    // }
    /*------------------------------------
                 Question : 05
         --------------------------------*/
    /*
    Mishka has got n empty boxes. For every i (1 ≤ i ≤ n), i-th box is a cube with side length ai.

    Mishka can put a box i into another box j if the following conditions are met:

    i-th box is not put into another box;
    j-th box doesn't contain any other boxes;
    box i is smaller than box j (ai < aj).
    Mishka can put boxes into each other an arbitrary number of times. He wants to minimize the number of visible boxes. A box is called visible iff it is not put into some another box.

    Help Mishka to determine the minimum possible number of visible boxes!

    Input
    The first line contains one integer n (1 ≤ n ≤ 5000) — the number of boxes Mishka has got.

    The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109), where ai is the side length of i-th box.

    Output
    Print the minimum possible number of visible boxes.

    3
    1 2 3

    1

    4
    4 2 4 3

    2

    Note :
    In the first example it is possible to put box 1 into box 2, and 2 into 3.

    In the second example Mishka can put box 2 into box 3, and box 4 into box 1.


    */

    // map<int, int> freq;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     freq[a[i]]++;
    // }

    // int ans = 0;

    // for (int i = 0; i < n; i++)
    //     ans = max(ans, freq[a[i]]);
    // cout << ans << endl;

    /*------------------------------------
                Question : 06
        --------------------------------*/
    /*
    Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.
    Input:
    N = 5
    vector = {1, 1, 1, 1, 1}
    X = 1
    Output:
    5
    Explanation: Frequency of 1 is 5
    */
    // int findFrequency(vector<int> v, int x)
    // {

    //     map<long long, int> cnt;

    //     for (auto u : v)
    //         cnt[u]++;
    //     return cnt[x];
    // }
    /*------------------------------------
           Question : 07
    --------------------------------*/
    /*Given a list of N words. Count the number of words that appear exactly twice in the list.

    Example 1:

    Input:
    N = 3
    list = {Geeks, For, Geeks}
    Output: 1
    Explanation: 'Geeks' is the only word that
    appears twice.
    Example 2:

    Input:
    N = 8
    list = {Tom, Jerry, Thomas, Tom, Jerry,
    Courage, Tom, Courage}
    Output: 2
    Explanation: 'Jerry' and 'Courage' are the
    only words that appears twice.*/

    // int t;
    // cin >> t;

    // while ( t-- ) {
    //     int n;
    //     cin >> n;
    //     map<string, int> cnt;

    //     for ( int i = 0; i < n; i++ ) {
    //         string s;
    //         cin >> s;
    //         cnt[s]++;
    //     }

    //     int ans = 0;

    //     for ( auto u : cnt ) {
    //         if ( u.second == 2 ) ans++;
    //     }

    //     cout << ans << endl;
    // }

    /*------------------------------------
           Question : 08
    --------------------------------*/
    /*
    You are given a string that is made up of words separated by spaces. Your task is to find the word with highest frequency, i.e. it appears maximum times in the sentence. If multiple words have maximum frequency, then print the word that occurs first in the sentence.

    Example 1:


    Input : S = "the devil in the sky"
    Output : the 2
    Explanation:
    The frequency of the is 2, so we return "the" and
    its frequency "2" i.e., "the 2"
    Example 2:

    Input : S = "this is not right"
    Output : this 1
    Explanation:
    Every word has the frequency of "1", so we return
    "this 1" as this occurs first in the sentence.
        */
    // #include <bits/stdc++.h>
    //     using namespace std;

    //     int main()
    //     {
    //         int t;
    //         cin >> t;

    //         while (t--)
    //         {
    //             string s;
    //             char c;
    //             cin >> c;
    //             getline(cin, s);
    //             s = c + s;

    //             string tmp;

    //             vector<string> v; /// the devil in the sky
    //             for (auto u : s)
    //             {
    //                 if (isspace(u))
    //                 {
    //                     v.push_back(tmp);
    //                     tmp.clear();
    //                 }

    //                 else
    //                     tmp += u;
    //             }

    //             v.push_back(tmp);

    //             map<string, int> cnt;

    //             int mxFrq = 0;
    //             for (auto u : v)
    //             {
    //                 cnt[u]++;
    //                 mxFrq = max(mxFrq, cnt[u]);
    //             }

    //             string ans;

    //             for (auto u : v)
    //             {
    //                 if (cnt[u] == mxFrq)
    //                 {
    //                     ans = u;
    //                     break;
    //                 }
    //             }

    //             cout << ans << " " << mxFrq << endl;
    //         }
    //     }
    /*------------------------------------
          Question : 09
    --------------------------------*/
    /*You are given a string that is made up of words separated by spaces. Your task is to find the word with highest frequency, i.e. it appears maximum times in the sentence. If multiple words have maximum frequency, then print the word that occurs first in the sentence.

    Example 1:


    Input : S = "the devil in the sky"
    Output : the 2
    Explanation:
    The frequency of the is 2, so we return "the" and
    its frequency "2" i.e., "the 2"
    Example 2:

    Input : S = "this is not right"
    Output : this 1
    Explanation:
    Every word has the frequency of "1", so we return
    "this 1" as this occurs first in the sentence. */
    // #include <bits/stdc++.h>
    //     using namespace std;

    //     int main()
    //     {
    //         int t;
    //         cin >> t;

    //         while (t--)
    //         {
    //             string s;
    //             char c;
    //             cin >> c;
    //             getline(cin, s);
    //             s = c + s;

    //             string tmp;

    //             vector<string> v; /// the devil in the sky
    //             for (auto u : s)
    //             {
    //                 if (isspace(u))
    //                 {
    //                     v.push_back(tmp);
    //                     tmp.clear();
    //                 }

    //                 else
    //                     tmp += u;
    //             }

    //             v.push_back(tmp);

    //             map<string, int> cnt;

    //             int mxFrq = 0;
    //             for (auto u : v)
    //             {
    //                 cnt[u]++;
    //                 mxFrq = max(mxFrq, cnt[u]);
    //             }

    //             string ans;

    //             for (auto u : v)
    //             {
    //                 if (cnt[u] == mxFrq)
    //                 {
    //                     ans = u;
    //                     break;
    //                 }
    //             }

    //             cout << ans << " " << mxFrq << endl;
    //         }
    //     }

    /*------------------------------------
        Question : 10
    --------------------------------*/
    /*
        Problem Statement
    You are given a sequence of positive integers of length N, a=(a
    1
    ​
    ,a
    2
    ​
    ,...,a
    N
    ​
    ). Your objective is to remove some of the elements in a so that a will be a good sequence.

    Here, an sequence b is a good sequence when the following condition holds true:

    For each element x in b, the value x occurs exactly x times in b.
    For example, (3,3,3), (4,2,4,1,4,2,4) and () (an empty sequence) are good sequences, while (3,3,3,3) and (2,4,1,4,2) are not.

    Find the minimum number of elements that needs to be removed so that a will be a good sequence.

    Constraints
    1≤N≤10
    5

    a
    i
    ​
    is an integer.
    1≤a
    i
    ​
    ≤10
    9

    Input
    Input is given from Standard Input in the following format:

    N
    a
    1
    ​
    a
    2
    ​
    ... a
    N
    ​

    Output
    Print the minimum number of elements that needs to be removed so that a will be a good sequence.

    Sample Input 1
    Copy
    4
    3 3 3 3
    Sample Output 1
    Copy
    1
    We can, for example, remove one occurrence of 3. Then, (3,3,3) is a good sequence.

    Sample Input 2
    Copy
    5
    2 4 1 4 2
    Sample Output 2
    Copy
    2
    We can, for example, remove two occurrences of 4. Then, (2,1,2) is a good sequence.

    Sample Input 3
    Copy
    6
    1 2 2 3 3 3
    Sample Output 3
    Copy
    0
    Sample Input 4
    Copy
    1
    1000000000
    Sample Output 4
    Copy
    1
    Remove one occurrence of 10
    9
    . Then, () is a good sequence.

    Sample Input 5
    Copy
    8
    2 7 1 8 2 8 1 8
    Sample Output 5
    Copy
    5
    */
    // #include <bits/stdc++.h>
    //     using namespace std;

    //     int main()
    //     {
    //         map<int, int> cnt;
    //         int n;
    //         cin >> n;
    //         for (int i = 1; i <= n; i++)
    //         {
    //             int a;
    //             cin >> a;
    //             cnt[a]++;
    //         }

    //         int ans = 0;

    //         for (auto u : cnt)
    //         {
    //             if (u.second >= u.first)
    //                 ans += (u.second - u.first);
    //             else
    //                 ans += u.second;
    //         }

    //         cout << ans << endl;
    //     }

    return 0;
}