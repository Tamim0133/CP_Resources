// Binary Search
#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int> v, int k)
{
    int s = 0;
    int e = v.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (k == v[m])
            return m;
        else if (k < v[m])
            e = m - 1;
        else
            s = m + 1;
    }
    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    cout << binary_search(v, 5) << endl;  // 4
    cout << binary_search(v, 10) << endl; // -1

    return 0;
}