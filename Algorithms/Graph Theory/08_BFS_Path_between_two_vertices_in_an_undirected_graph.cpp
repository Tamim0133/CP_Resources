/* Weather two nodes are getting connected */

/*
    Take the following graph as input and determine weather nodes 2 and 6 are connected using BFS
    9 11 
    
    0 2 
    7 8 
    0 4 
    0 5 
    6 7 
    1 4 
    1 5 
    2 3 
    2 4 
    4 5 
    8 6 
    
    2 6 
    
    O/P : Not Connected 
    
    3 2 
    1 2 
    2 3 
    
    1 3 
    
    O/P : Yes Connected 
    
    There is a path from 1 to 3, 1 -> 2 -> 3
    
    
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int visited[N];

vector < int >adj_list[N];

int source, destination;

bool
bfs (int src)
{
  queue < int >q;

  visited[src] = 1;
  q.push (src);

  while (!q.empty ())
    {
      int head = q.front ();
      q.pop ();

      // cout << head << endl;
    for (int adj_node:adj_list[head])
	{
	  if (adj_node == destination)
	    return true;
	  if (visited[adj_node] == 0)
	    {
	      visited[adj_node] = 1;
	      q.push (adj_node);
	    }
	}
    }

  return false;
}


int
main ()
{
  int nodes, edges;
  cin >> nodes >> edges;

  for (int i = 0; i < edges; i++)
    {
      int u, v;
      cin >> u >> v;
      adj_list[u].push_back (v);
      adj_list[v].push_back (u);
    }

  cin >> source >> destination;

  bfs (source) ? cout << "YES ! Connected. " << endl : cout << "Not Connected ." << endl;
}
