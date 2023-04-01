

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> adjList[N];
int visited[N];
int parent[N];

bool detect_cycle(int src)
{
    visited[src] = 1;

    for (int adj_node : adjList[src])
    {
        if (adj_node == parent[src])
        {
            continue;
        }
        if (visited[adj_node] == 0)
        {

            parent[adj_node] = src;

            bool ok = detect_cycle(adj_node);
            if (ok)
            {
                return true;
            }
        }
        if (visited[adj_node] == 1)
        {
            return true;
        }
    }

    visited[src] = 2;
    return false;
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    while (edge--)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool cycle = false;

    for (int i = 1; i <= node; i++)
    {
        if (visited[i] == 0)
        {
            bool ok = detect_cycle(i);
            if (ok)
            {
                cycle = true;
                break;
            }
        }
    }
    if (cycle)
    {
        cout << "Cycle Exists" << endl;
    }
    else
    {
        cout << "No Cycle\n";
    }
}
