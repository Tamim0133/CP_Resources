/*

    1 --- 2 --- 3 --- 4
          |     |
          5 --- 6


    6 6

    1 2
    2 3
    2 5
    3 4
    3 6
    5 6

    6  ->  3  ->  2  ->  1

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N], parent[N];

void dfs(int src)
{
    visited[src] = 1;

    for (auto i : adj_list[src])
    {
        if (!visited[i])
        {
            parent[i] = src; // এইটুকুই খালি চেঞ্জ
            dfs(i);
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 1;
    int dst = 6;

    dfs(src);

    // প্রিন্ট করার টেকনিকটা একটু আলাদা
    vector<int> path;
    int selected_node = dst;
    while (1)
    {
        path.push_back(selected_node);

        if (selected_node == src) // টারমিনেটিং কন্ডীনেশন
            break;

        selected_node = parent[selected_node];
    }

    reverse(path.begin(), path.end());
    for (auto i : path)
        cout << i << " ";
    cout << endl;

    return 0;
}