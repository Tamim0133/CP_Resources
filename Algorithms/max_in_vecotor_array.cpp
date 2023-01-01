#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    int k = v[max_element(v.begin(), v.end()) - v.begin()];

    cout << k << "\n";

    return 0;
}