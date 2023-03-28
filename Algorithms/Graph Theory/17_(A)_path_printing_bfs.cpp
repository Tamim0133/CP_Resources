/*
Q : CSES Message Route

 Input :

 5 5

1 2
1 3
1 4
2 3
5 4

Output :
3
1 4 5

*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> adj_list[N];
int visited[N], level[N];

int parent[N]; // Path Printing এর জন্য আমরা একটা Parent Array নিয়ে চলবো ।

void bfs(int src)
{
    visited[src] = 1;
    level[src] = 1;

    parent[src] = -1; // Source -1

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for (auto i : adj_list[head])
        {
            if (visited[i] == 0)
            {
                parent[i] = head; // Parent
                visited[i] = 1;
                level[i] = level[head] + 1; // এই লেভেল করা ম্যান্ডেটরি না । এই প্রশ্নের জন্য করা ।
                q.push(i);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src_node = 1;
    bfs(src_node);

    int dest_node = n;

    // যদি Destination Visit করা না থাকে তাহলে Impossible
    if (visited[dest_node] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << level[dest_node] << endl;

    // Path এর জন্য একটা এরে
    vector<int> path;

    int selected_node = dest_node;

    // এইটুকু মেইন কনসেপ্ট
    while (1)
    {
        path.push_back(selected_node);
        if (selected_node == src_node)
        {
            break;
        }
        selected_node = parent[selected_node];
    }

    // রিভার্স করা লাগে
    reverse(path.begin(), path.end());

    for (int node : path)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;

    return 0;
}