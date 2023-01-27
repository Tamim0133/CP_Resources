#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l;
    int j = h;

    while (i < j)
    {
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[j], a[l]);
    return j;
}
/*

*/
void quicksort(int arr[], int s, int e)
{
    if (s < e)
    {
        int pi = partition(arr, s, e);
        quicksort(arr, s, pi - 1);
        quicksort(arr, pi + 1, e);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(arr, 0, n - 1);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}