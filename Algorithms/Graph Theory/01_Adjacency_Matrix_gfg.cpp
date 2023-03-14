#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int adjMat[n + 1][n + 1] = {}; // এম্পটী ব্র্যকেট সবগুলা Matrix ভ্যাল্যু কে জিরো হিসেবে ইনিশিয়ালাইজ করে । O(n^2)
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
        // for a directed graph with an edge pointing from u
        // to v,we just assign adjMat[u][v] as 1
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
