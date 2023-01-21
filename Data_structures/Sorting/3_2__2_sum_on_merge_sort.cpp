/*
    WAP that takes n integer numbers and an integer k, and how many pairs of numbers in the array which sums to k. You have to do it inside the Merge Sort function, divide and conquer fashion in O(nlogn).

    Sample input
    Sample output
    5
    6 1 3 2 4
    5
    2
    6
    5 6 7 8 0 1
    16
    0


    In sample 1, k = 5. a[1] + a[4] = 1 + 4 = 5 and a[2] + a[3] = 3 + 2 = 5. So the output is 2.
    In sample 2, k = 16 and no pair of numbers sum to 16. It is not allowed to use the same index twice. For example a[3] + a[3] = 8 + 8 = 16 but we cannot use index 3 twice.

*/
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> merge_sort(vector<int> a)
{
    if (a.size() <= 1)
        return a;
    int mid = a.size() / 2;

    vector<int> b;
    vector<int> c;

    for (int i = 0; i < mid; i++)
        b.push_back(a[i]);
    for (int i = mid; i < a.size(); i++)
        c.push_back(a[i]);

    vector<int> sorted_b = merge_sort(b);
    vector<int> sorted_c = merge_sort(c);

    vector<int> sorted_a;

    int idx1 = 0, idx2 = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (idx1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
        else if (idx2 == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else if (sorted_b[idx1] < sorted_c[idx2])
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
    }
    if (sorted_a.size() == n)
    {
        int i = 0, j = n - 1, count = 0;
        while (i < j)
        {
            if ((sorted_a[i] + sorted_a[j]) > k)
                j--;
            else if ((sorted_a[i] + sorted_a[j]) < k)
                i++;
            else if (sorted_a[i] + sorted_a[j] == k)
            {
                count++;
                i++;
                j--;
            }
        }
        cout << count << endl;
    }
    return sorted_a;
}
int main()
{
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> k;

    vector<int> ans = merge_sort(a);

    // for (auto i : ans)
    //     cout << i << " ";
    // cout << endl;
    return 0;
}
