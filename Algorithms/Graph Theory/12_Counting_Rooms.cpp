// problem link - https://cses.fi/problemset/task/1192

/*
5 8
########
#..#...#
####.#.#
#..#...#
########
Output -> 3
while there exists an empty cell
    - find an empty unvisited cell
    - run bfs() from that cell

# গুলা উয়াল । অইগুলা দিয়ে জাউয়া যায় না ।
. গুলা দিয়ে জাউয়া লাগবে । এখন আমরা সোর্স থেকে শুরু করবও , তারপর DFS/ BFS চালাবো ।
BFS/DFS যতোগুলা চালাতে হবে ঠিক ততো গুলা রুম ই আছে ।

BFS/DFS এর Traversal এর সময় Source থেকে Destination পর্যন্ত সবগুলা নোড কে কানেক্ট করে।



*/

#include <bits/stdc++.h>
using namespace std;
const int N = 2002;

int maze[N][N], visited[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

bool is_safe(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;
    if (maze[x][y] == -1)
    {
        return false;
    }
    return true;
}

void bfs(pair<int, int> src)
{

    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;

    q.push(src);

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};

            if (is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                q.push(adj_node);
            }
        }
    }
}

pair<int, int> find_unvisited()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && maze[i][j] == 0)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            if (input[j] == '#')
            {
                maze[i][j] = -1;
            }
        }
    }

    // for(int i = 0 ; i < n ; i++) {
    //     for(int j = 0; j < m ; j++) {
    //         cout<<maze[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    int room_cnt = 0;

    while (true)
    {
        pair<int, int> unvisited_pos = find_unvisited();
        if (unvisited_pos == pair<int, int>(-1, -1))
        {
            break;
        }
        bfs(unvisited_pos);
        room_cnt++;
    }
    cout << room_cnt << endl;
    return 0;
}
/*

PseudoCode:
রুম সংখ্যা = ০ ;

find_unvisited()
{
    for(0 -> n)
        for(o -> m )
            যদি Unvisited এবং maze 0 হলে
                bfs();
                রুম সংখ্যা ++;
}

main()
{
find_unvisited();
cout << রুম সংখ্যা << endl;
*/