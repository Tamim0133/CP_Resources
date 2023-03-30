// /*
// CSES Round Trip Problem
// https://cses.fi/problemset/task/1669/
// i/P :
// 5 6
// 1 3
// 1 2
// 5 3
// 1 5
// 2 4
// 4 5

// o/P :
// 4
// 3 5 1 3

// i/P :
// 6 6

// 1 2
// 2 3
// 2 5
// 3 4
// 3 6
// 5 6

// i/P :
// 3 3
// 1 2
// 2 3
// 1 3

// */

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 2e5;

// vector<int> adj_list[N];

// int visited[N];
// int parent[N];
// int st;
// int ed;

// bool detect_cycle(int src)
// {
//     visited[src] = 1;

//     for (auto adj_node : adj_list[src])
//     {
//         if (adj_node == parent[src])
//             continue;
//         if (visited[adj_node] == 0)
//         {
//             parent[adj_node] = src;

//             bool ok = detect_cycle(adj_node);

//             if (ok)
//             {
//                 return true;
//             }
//         }

//         else if (visited[adj_node] == 1)
//         {
//             st = src;
//             ed = adj_node;
//             return true;
//         }
//     }

//     visited[src] = 2;
//     return false;
// }

// int main()
// {
//     int node, edge;
//     cin >> node >> edge;

//     while (edge--)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj_list[u].push_back(v);
//         adj_list[v].push_back(u);
//     }

//     bool cycle = false;
//     for (int i = 0; i <= node; i++)
//     {
//         if (visited[i] == 0)
//         {
//             bool ok = detect_cycle(i);
//             if (ok)
//             {
//                 cycle = true;
//                 break;
//             }
//         }
//     }

//     if (cycle)
//     {
//         vector<int> cities;
//         int temp = st;
//         cities.push_back(st);

//         while (temp != ed)
//         {
//             cities.push_back(parent[temp]);
//             temp = parent[temp];
//         }
//         cities.push_back(st);

//         cout << cities.size() << endl;

//         for (auto i : cities)
//             cout << i << " ";
//     }
//     else
//         cout << "IMPOSSIBLE" << endl;

//     return 0;
// }

// /*
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 2e5;

// vector<int> adj_list[N];

// int visited[N], parent[N];

// int st, ed;

// bool detect_cycle(int src)
// {
//     visited[src] = 1;

//     for (auto i : adj_list[src])
//     {
//         if (i == parent[src])
//             continue;
//         if (visited[i] == 0)
//         {
//             parent[i] = src;

//             bool ok = detect_cycle(i);

//             if (ok)
//             {
//                 return true;
//             }
//         }
//         else if (visited[i] == 1)
//         {
//             st = src;
//             ed = i;
//             return true;
//         }
//     }
//     visited[src] = 2;
//     return false;
// }

// int main()
// {
//     int nodes, edges;
//     cin >> nodes >> edges;

//     while (edges--)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj_list[u].push_back(v);
//         adj_list[v].push_back(u);
//     }

//     bool cycle = false;

//     for (int i = 1; i <= nodes; i++)
//     {
//         if (visited[i] == 0)
//         {
//             bool ok = detect_cycle(i);
//             if (ok)
//             {
//                 cycle = true;
//                 break;
//             }
//         }
//     }

//     if (cycle)
//     {
//         // for (int i = 1; i <= nodes; i++)
//         // cout << i << "->" << parent[i] << endl;
//         vector<int> path;
//         // cout << "START " << st << "End " << ed << endl;
//         int selected_node = st;
//         while (1)
//         {
//             path.push_back(selected_node);
//             if (selected_node == ed)
//             {
//                 break;
//             }
//             selected_node = parent[selected_node];
//         }
//         path.push_back(st);

//         cout << path.size() << endl;

//         for (auto i : path)
//             cout << i << " ";
//         cout << endl;
//     }
//     else
//     {
//         cout << "IMPOSSIBLE" << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> adjList[N];
int visited[N];
int parent[N];

int st, ed;

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

        for (auto city : cities)
        {
            cout << city << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}
