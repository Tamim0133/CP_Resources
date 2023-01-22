#include <bits/stdc++.h>
using namespace std;
int merge(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;
    int inv = 0;

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
            inv += n1 - i;
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
    return inv;
}

int merge_sort(int arr[], int l, int h)
{
    int inv = 0;
    if (l < h)
    {
        int m = (l + h) / 2;
        inv += merge_sort(arr, l, m);
        inv += merge_sort(arr, m + 1, h);
        inv += merge(arr, l, m, h);
    }
}

int main()
{
    int arr[] = {30, 12, 12, 9, 17, 13, 8};

    int inv = merge_sort(arr, 0, 6);

    cout << inv << endl;

    return 0;
}