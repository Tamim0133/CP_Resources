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

o/p : 1 2 3 6
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int nodes, edges;
int adj_mat[100][100];

int visited[N], parent[N];

void bfs(int src)
{

    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while (!q.empty())
    {

        int head = q.front();
        q.pop();

        // cout << head << " ";

        for (int i = 1; i <= nodes; i++)
        {

            if (adj_mat[head][i] == 1 && (visited[i] == 0))
            {

                q.push(i);
                parent[i] = head;
                visited[i] = 1;
            }
        }
    }
}

int main()
{

    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;
    }

    int src = 1;
    int dst = 6;

    bfs(src);

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