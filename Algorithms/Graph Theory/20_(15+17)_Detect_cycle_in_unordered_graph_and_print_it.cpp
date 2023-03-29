/*

i/P :
5 6
1 3
1 2
5 3
1 5
2 4
4 5

o/P :
4
3 5 1 3

i/P :
6 6

1 2
2 3
2 5
3 4
3 6
5 6

i/P :
3 3
1 2
2 3
1 3

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> adj_list[N];

int visited[N];
int parent[N];
int st;
int ed;

bool detect_cycle(int src)
{
    visited[src] = 1;

    for (auto adj_node : adj_list[src])
    {
        if (adj_node == parent[src])
            continue;
        if (visited[adj_node] == 0)
        {
            parent[adj_node] = src;

            bool ok = detect_cycle(adj_node);

            if (ok)
            {
                return true;
            }
        }

        else if (visited[adj_node] == 1)
        {
            st = src;
            ed = adj_node;
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
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool cycle = false;
    for (int i = 0; i <= node; i++)
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
        vector<int> cities;
        int temp = st;
        cities.push_back(st);

        while (temp != ed)
        {
            cities.push_back(parent[temp]);
            temp = parent[temp];
        }
        cities.push_back(st);

        cout << cities.size() << endl;

        for (auto i : cities)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}