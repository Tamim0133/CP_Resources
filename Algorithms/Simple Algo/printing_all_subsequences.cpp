#include <bits/stdc++.h>
using namespace std;

void printSub(int arr[], int idx, vector<int> &subarr, int n)
{
    if (idx == n)
    {
        for (auto i : subarr)
            cout << i << " ";
        cout << endl;
        return;
    }

    subarr.push_back(arr[idx]);
    printSub(arr, idx + 1, subarr, n);

    subarr.pop_back();
    printSub(arr, idx + 1, subarr, n);
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v;

    printSub(arr, 0, v, n);

    return 0;
}