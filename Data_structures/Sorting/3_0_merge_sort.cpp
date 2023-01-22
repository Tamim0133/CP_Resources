#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        b[j] = arr[m + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

int main()
{
    int arr[] = {30, 12, 12, 9, 17, 13, 8};

    merge_sort(arr, 0, 6);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}