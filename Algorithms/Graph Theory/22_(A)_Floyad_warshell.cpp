// Pseudocode: Floyd-Warshall

// Input -> A weighted graph as an adjacency matrix
// Output -> All pair shortest distance

// Time complexity ->  O(V^3)
// Space Complexity -> O(V^2)

// - create a distance_matrix "d" where d[i][j] = x where there is a direct
//   edge from node "i" to node "j" and the cost is "x"
// - for all node "i" d[i][i] = 0
// - for all nodes "i" & "j" where there isn't any direct edge from "i" to "j",
//     d[i][j] = INF

// - for all node "k" -> O(1)
//     - for all node "u" -> O(1)
//         - for all node "v" -> O(1)
//             - d[u][v] = min(d[u][v], d[u][k] + d[k][v] )    => O(1)

// - output all pair shortest distance "d"

// cses :

// problem link - https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
const long long INF = 1e18;
long long d[N][N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (d[u][v] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << d[u][v] << endl;
        }
    }

    return 0;
}

/*
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

*/

/*
5
5
8
-1
3


*/
