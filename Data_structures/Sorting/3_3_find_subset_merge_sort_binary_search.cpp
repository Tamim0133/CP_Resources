/*
    WAP that takes 2 integer arrays with distinct elements as input, and checks if array 1 is a subset of array 2. Solve the problem in O(nlogn) or better.


    Sample input
    Sample output
    3
    7 2 3
    5
    7 6 3 2 1
    YES




    3
    1 2 3
    3
    3 2 1
    YES
    3
    1 2 4
    3
    3 2 1
    NO


    In Sample 3, array 1 is not a subset of array 2 because 4 does not occur in array 2.

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

    return sorted_a;
}

int binarySearch(vector<int> arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    while (high >= low)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

bool isSubset(vector<int> arr1, vector<int> arr2)
{
    int i = 0;

    for (i = 0; i < arr1.size(); i++)
    {
        if (binarySearch(arr2, arr1[i]) == -1)
            return 0;
    }

    return 1;
}

int main()
{
    int m;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> arr1 = merge_sort(a);
    vector<int> arr2 = merge_sort(b);

    if (isSubset(arr1, arr2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
