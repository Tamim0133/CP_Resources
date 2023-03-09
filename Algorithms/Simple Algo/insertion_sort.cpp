/*-------------------------
        Insertion Sort
----------------------------*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;

    int arr[6] = {12, 45, 23, 51, 19, 8};

    for (int i = 1; i < n; i++)
    {
        int idx = i;
        while (idx >= 1)
        {
            if (arr[idx] < arr[idx - 1])
            {
                swap(arr[idx], arr[idx - 1]);
                idx--;
            }
            else
            {
                break;
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