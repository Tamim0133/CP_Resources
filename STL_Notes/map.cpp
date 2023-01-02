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

    return 0;
}