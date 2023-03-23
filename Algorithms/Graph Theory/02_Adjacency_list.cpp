#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 9;
    vector<int> adjList[n + 1];

    int e;
    cin >> e;

    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto child : adjList[i])
            cout << child << " ";
        cout << endl;
    }

    return 0;
}