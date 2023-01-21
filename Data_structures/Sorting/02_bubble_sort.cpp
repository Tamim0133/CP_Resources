/*-------------------------
        Bubble Sort
----------------------------*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;

    int arr[6] = {12, 45, 23, 51, 19, 8};

    for (int step = 0; step < n - 1; step++)
    {
        for (int i = 0; i < n - 1 - step; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}