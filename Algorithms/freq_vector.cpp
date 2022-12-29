#include <bits/stdc++.h>
using namespace std;

vector<int> freq_vec(vector<int> v, int n)
{
    int max = v[0];

    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
            max = v[i];
    }

    vector<int> freq(max + 1, 0);

    for (int i = 0; i < n; i++)
        freq[v[i]]++;

    return freq;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n), freq;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    freq = freq_vec(v, n);

    for (int i = 1; i <= freq.size(); i++)
        cout << i << " " << freq[i] << endl;
    return 0;
}