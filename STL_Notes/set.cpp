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

    return 0;
}
