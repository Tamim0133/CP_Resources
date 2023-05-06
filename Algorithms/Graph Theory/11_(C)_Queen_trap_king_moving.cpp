
#include <bits/stdc++.h>
using namespace std;

bool visited[1005][1005] = {false};

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void queenMoves(int x, int y, int n, vector<vector<int>> &grid)
{

    grid[x][y] = 1;

    for (int i = 0; i < 8; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        while (cx >= 1 && cy >= 1 && cx <= n && cy <= n)
        {
            grid[cx][cy] = 1;
            cx += dx[i];
            cy += dy[i];
        }
    }
}

void bfs(int x, int y, int n, vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int dx_, dy_;
            dx_ = u.first + dx[i];
            dy_ = u.second + dy[i];
            if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= n && !visited[dx_][dy_] && grid[dx_][dy_] != 1)
            {
                visited[dx_][dy_] = true;
                q.push({dx_, dy_});
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    int q1, q2, k1, k2, d1, d2;
    cin >> q1 >> q2 >> k1 >> k2 >> d1 >> d2;

    queenMoves(q1, q2, n, grid);

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << grid[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    bfs(k1, k2, n, grid);

    if (visited[d1][d2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;


bool visited[1005][1005] = {false};


int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};


void queenMoves(int x, int y, int n, vector<vector<int>> &grid)
{


   grid[x][y] = 1;


   for (int i = 0; i < 8; i++)
   {
       int cx = x + dx[i];
       int cy = y + dy[i];


       while (cx >= 1 && cy >= 1 && cx <= n && cy <= n)
       {
           grid[cx][cy] = 1;
           cx += dx[i];
           cy += dy[i];
       }
   }
}


void dfs(int x, int y, int n, vector<vector<int>> &grid)
{
   visited[x][y] = true;
   // cout << x << " " << y << endl;


   for (int i = 0; i < 8; i++)
   {
       int dx_, dy_;
       dx_ = x + dx[i];
       dy_ = y + dy[i];
       if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= n && !visited[dx_][dy_] && grid[dx_][dy_] != 1)
       {
           dfs(dx_, dy_, n, grid);
       }
   }
}


int main()
{
   int n;
   cin >> n;


   vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
   int q1, q2, k1, k2, d1, d2;
   cin >> q1 >> q2 >> k1 >> k2 >> d1 >> d2;


   queenMoves(q1, q2, n, grid);


   // for (int i = 1; i <= n; i++)
   // {
   //     for (int j = 1; j <= n; j++)
   //     {
   //         cout << grid[i][j] << "  ";
   //     }
   //     cout << endl;
   // }


   dfs(k1, k2, n, grid);


   if (visited[d1][d2])
       cout << "YES" << endl;
   else
       cout << "NO" << endl;


   return 0;
}



*/