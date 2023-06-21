// Brute Force
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k;
    cin >> k;

    int maxi = INT_MIN;
    for (int i = 0; i < n - k + 1; i++)
    {
        int x = 0;
        for (int j = i; j < i + k; j++)
        {
            // cout << a[j] << " ";
            x += a[j];
        }
        // cout << endl;
        maxi = max(x, maxi);
    }
    cout << maxi << endl;

    return 0;
}
/*
6
1 2 4 3 4 2
3
1 2 4
2 4 3
4 3 4
3 4 2

max : 11 (3 4 3)
*/