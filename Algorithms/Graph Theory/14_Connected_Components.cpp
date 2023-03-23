/*
    1 ----5
               3
    0
    |
    2------4

    Eikhane No of Components 3

    i/p :
        6 3
        1 5
        0 2
        2 4

    o/p:
        3



*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int> adj_list[N];
int visited[N];

void dfs(int node)
{
    visited[node] = 1;

    for (auto i : adj_list[node])
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{

    int nodes, edges, count = 0;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            count++;
        }
    }

    cout << count << endl; // No of components

    return 0;
}