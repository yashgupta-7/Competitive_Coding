#include<bits/stdc++.h>
using namespace std;

int steps = 0;

void addEdge(vector<int> adj[], int child, int parent)
{
	adj[parent].push_back(child);
}

void dfs(vector<int> adj[], int color[], int root, int col)
{
  color[root] = col;
  for (auto x : adj[root])
  {
  	dfs(adj, color, x, col);
  }
}

void dfsCol(vector<int> adj[], int color[], int f_color[], int root)
{
  if (color[root] != f_color[root])
  {
  	dfs(adj, color, root, f_color[root]);
  	steps++;
  }

  for (auto x : adj[root])
  {
  	dfsCol(adj, color, f_color, x);
  }
}


int main()
{
	int n; cin >> n;
	vector<int> adj[n+1];
	int color[n+1];
	color[1]=0;
	for (int i = 2; i < n+1; ++i)
	{
		int p_i;
		cin>>p_i;
		addEdge(adj, i , p_i);
	}
	

	int f_color[n+1];
	for (int i = 1; i < n+1; ++i)
	{
		cin>> f_color[i];
	}
    dfsCol(adj, color, f_color, 1);
    cout<<steps;
}