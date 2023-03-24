/*
Graph Coloring Concept এর উপর ভিত্তি করে এই প্রশ্ন সমাধান করা যায় । যদি গ্রাফ কালারেবল হয় তাহলে গ্রাফ Bi-partite । কালারেবল না হলে Bi-partite না ।
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int> adj_list[N];
int visited[N], color[N];

bool colorable(int n)
{
    visited[n] = 1;

    for (auto i : adj_list[n])
    {
        if (!visited[i])
        {
            if (color[n] == 1)
                color[i] = 2;
            else
                color[i] = 1;

            bool bi_colorable = colorable(i);

            if (!bi_colorable)
                return false;
        }
        //  যদি নোডটা আগে ভিজিট করে থাকই তাহলে চেক করবও অইটা আর  adjacent এর কালার সেম কিনা
        else if (visited[i])
        {
            if (color[i] == color[n])
                return false;
        }
    }
    return true;
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

    bool ok = true;
    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == 0)
        {
            // Source কে ১ দিয়ে কালার করলাম
            color[i] = 1;
            if (!colorable(i))
            {
                ok = 0;
                break;
            }
        }
    }
    if (ok) // যদি বাই-কালারেবল হয় তাহলে গ্রাফ বাইপারটাইট ও হবে
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

