// Problem link - https://cses.fi/problemset/task/1193
/*
        0         -> Root Level
      /   \
    0       0     -> Level 01 : Root theke dui level dure
   / \     / \
 0    0   0    0  -> Level 02 : Root theke ak level dure

     A           -> Root Level 0
    /  \
   B    C        -> Level 01 :  Root theke ek level dur e
        |
        D        -> Level 02 : Root theke Dui level dur e
       /
      E          -> Level 03 : Root theke Tin level Dur e

    Tarmane amader jodi shortest path ber korte bola hoy tahole amra level print kore dibo for Un-Directed Graphs . Source jodi root na hoy tahole source node er level destination theke biyog korleo kaj hobe .

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited[N];
int level[N];

vector<int> adj_list[N];

void bfs(int src)
{
    queue<int> q;

    visited[src] = 1;
    level[src] = 0; // new line added
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;

                level[adj_node] = level[head] + 1; // new line added

                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 0;
    bfs(src);

    for (int i = 0; i < nodes; i++)
    {
        cout << "node " << i << " -> level: " << level[i] << endl;
    }
    return 0;
}

/*
(0)   (1)   (2)
0 --- 1------2 ---- 3 (3)
      |      |
      |      |
  (2) 5------4 (3)

6 6

0 1
2 3
1 5
1 2
2 4
5 4

*/
