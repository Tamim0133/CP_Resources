/// In the name of ALLAH

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Vector Declaration
    vector<int> v;

    // vector এর শেষে একটা এলিমেন্ট যোগ করা
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << v[0] << " " << v[1] << " " << v[2] << endl; /// 1 2 3

    v[1] = 3;                                           // vector এর জেকোন position এ array এর মতো change করা যায় ।
    cout << v[0] << " " << v[1] << " " << v[2] << endl; /// 1 3 3

    // সাইজ print করার জন্য
    cout << v.size() << endl; /// 3
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " "; /// 1 3 3
    cout << endl;

    // array এর মতো second bracket দিয়ে declare করা যায় ।
    vector<int> v1 = {2, 3, 4};

    cout << v1.size() << endl; /// 3
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " "; /// 2 3 4
    cout << endl;

    // vector clear করার জন্য
    v.clear();
    cout << v.size() << endl;   /// 0
    cout << v.empty() << endl;  /// 1
    cout << v1.empty() << endl; /// 0

    // ভেক্টর কে রিসাইজ করে এবং বাকি এলিমান্ট গুলাকে জিরো দিয়ে  ইনিশিয়ালাইয করে ।
    v1.resize(5);
    cout << v1.size() << endl; /// 5
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " "; /// 2 3 4 0 0
    cout << endl;

    // শুরুতেই ৫ সাইজের একটা ভেক্টর Declare করে সবগুলাকে ০ দিয়ে initialize করা ।
    vector<int> a(5);

    cout << a.size() << endl; /// 5
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " "; /// 0 0 0 0 0
    cout << endl;

    // ভেক্টর কপি
    a = v1;

    for (auto u : a)
        cout << u << " "; /// 2 3 4 0 0 for each loop (only for printing)
    cout << endl;

    // Iterator (pointer concept )
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++)
        cout << *it << " "; /// 2 3 4 0 0
    cout << endl;

    a = {3, 4, 5, 1, 2};

    sort(a.begin(), a.end()); /// O(n*log(n))

    for (auto u : a)
        cout << u << " "; /// 1 2 3 4 5
    cout << endl;

    sort(a.rbegin(), a.rend());

    for (auto u : a)
        cout << u << " "; /// 5 4 3 2 1
    cout << endl;

    a = {3, 4, 5, 1, 2};

    sort(a.begin(), a.end(), greater<int>());

    for (auto u : a)
        cout << u << " "; /// 5 4 3 2 1
    cout << endl;

    a = {3, 4, 5, 1, 2};

    reverse(a.begin(), a.end());

    for (auto u : a)
        cout << u << " "; /// 2 1 5 4 3
    cout << endl;

    cout << a.back() << endl; /// 3 (gives the last element )
    a.pop_back();             /// O(1) complexity.
    cout << a.back() << endl; /// 4

    a = {3, 4, 5, 1, 2};
    cout << *a.begin() << endl; /// 3 (a.begin() is basically pointing at the start index pointer and by dereferencing we get its value)

    // TO delete the first element of a vector
    a.erase(a.begin()); /// O(n) complexity.
    for (auto u : a)
        cout << u << " "; /// 4 5 1 2
    cout << endl;

    a.erase(a.begin() + 2);
    for (auto u : a)
        cout << u << " "; /// 4 5 2
    cout << endl;

    // The confusing concept of Unique Function :

    a = {1, 1, 2, 2, 2, 3, 3};
    unique(a.begin(), a.end());

    for (auto u : a)
        cout << u << " "; /// 1 2 3 2 2 3 3
    cout << endl;

    a = {1, 1, 2, 2, 2, 3, 3};
    int n = unique(a.begin(), a.end()) - a.begin();

    cout << n << endl; /// 3
    for (int i = 0; i < n; i++)
        cout << a[i] << " "; /// 1 2 3
    cout << endl;

    a = {2, 3, 1, 5};
    cout << max_element(a.begin(), a.end()) - a.begin() << endl; /// 3 (Position of Max_Element)
    cout << *max_element(a.begin(), a.end()) << endl;            /// 5 (value of max element)

    vector<int>::iterator it = min_element(a.begin(), a.end());
    cout << *it << endl;

    return 0;
}