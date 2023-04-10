/*

You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle

Input:
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

Output:
YES
1 2 4 1

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
long long d[N];

int parent[N];

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    bool negative_cycle = false;
    int last_updated_node = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (pair<int, int> adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    parent[v] = u;
                    if (i == n)
                    {
                        negative_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }
    if (negative_cycle == true)
    {
        cout << "YES" << endl;

        int selected_node = last_updated_node;
        for (int i = 1; i <= n - 1; i++)
        {
            selected_node = parent[selected_node];
        }

        int first_node = selected_node;

        vector<int> cycle;
        cycle.push_back(selected_node);

        while (true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);
            if (selected_node == first_node)
            {
                break;
            }
        }

        reverse(cycle.begin(), cycle.end());

        for (int node : cycle)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

/*
    // Pseudocode: Bellman-Ford

Input -> A weighted graph & a src node (with no negative cycles) & a destination_node
Ouput -> Shortest distance from src node to all other nodes


n -> number of nodes in graph
m -> number of edges in graph


time complexity -> O(n*m)
Space Complexity -> O(n)



u ----> v

d[u] + c(u,v) < d[v]
=> d[v] = d[u] + c(u,v)



- create a distance array "d" with all values to infinity
- create a parent array
- d[src] = 0

- negative_cycle = false
- last_updated_node = -1

- for i = 1 to n:
    - for all edge e(u, v, w):
        - if d[u] + w < d[v]:
            - d[v] = d[u] + w
            - parent[v] = u
            - if i == n:
                - negative_cycle = true
                - last_updated_node = v

- if negative_cycle == false: -> O(n)
    - print the distance array "d"
    - selected_node = destination_node
    - declare a vector path
    - while true:
        - path.push_back(selected_node)
        - if selected_node == src:
            break
        - selected_node = parent[selected_node]
    - reverse the vector path
    - print the path

else:  ->  O(n)
    - print negatice cycle exists
    - selected_node = last_updated_node
    - for i = 1 to n-1:  -> O(n)
        - selected_node = parent[selected_node]
    - first_node = selected_node
    - declare a vector "cycle"
    - cycle.push_back(selected_node)
    - while true: -> O(n)
        - selected_node = parent[selected_node]
        - cycle.push_back(selected_node)
        - if selected_node == first_node:
            - break
    - reverse the "cycle" vector
    - print the cycle

*/