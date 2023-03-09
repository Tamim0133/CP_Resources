#include <bits/stdc++.h>
using namespace std;

const int maxN = 100;
int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> adjList[maxN];

    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({u, w});
        adjList[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto j : adjList[i])
            cout << "{" << j.first << " , " << j.second << " } ";
        cout << endl;
    }

    return 0;
}
/*
1 3 3
1 2 2
1 4 6
2 8 6
2 3 7
8 4 3
3 4 5

5 7
1 3 3
1 2 2
1 4 6
2 8 6
2 3 7
8 4 3
3 4 5
1 -> {1 , 3 } {1 , 2 } {1 , 6 }
2 -> {1 , 2 } {2 , 6 } {2 , 7 }
3 -> {1 , 3 } {2 , 7 } {3 , 5 }
4 -> {1 , 6 } {8 , 3 } {3 , 5 }
5 ->

*/