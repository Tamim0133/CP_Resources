/* BFS using adj matrix  */

/*
 0 --- 1 --- 2 --- 3
          |     |
          |     |
          5 --- 4
    # of node -> 6
    # of edge -> 6
    list of adj nodes ->
    6 6
    0 1
    1 2
    2 3
    1 5
    2 4
    5 4
*/
#include <bits/stdc++.h>
using namespace std;

int nodes, edges;

int adj_mat[100][100] = { };

const int N = 1e5;

int visited[N];

void
dfs (int src)
{


  visited[src] = 1;
  cout << src << " ";

  for (int i = 0; i < nodes; i++)
    {

      if (adj_mat[src][i] == 1 && (visited[i] == 0))
	{

	  dfs (i);
	}
    }
}


int
main ()
{

  cin >> nodes >> edges;




  for (int i = 0; i < edges; i++)
    {
      int u, v;
      cin >> u >> v;
      adj_mat[u][v] = 1;
      adj_mat[v][u] = 1;
    }

  for (int i = 0; i < nodes; i++)
    {
      for (int j = 0; j < nodes; j++)
	{
	  cout << adj_mat[i][j] << " ";
	}
      cout << endl;
    }

  cout << endl;
  int src = 0;
  dfs (src);
}
