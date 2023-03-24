#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int adj_mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj_mat[i][j];
        }
    }

    vector<int> adj_list[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_mat[i][j] == 1)
            {
                adj_list[i].push_back(j);
                // adj_list[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto j : adj_list[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
