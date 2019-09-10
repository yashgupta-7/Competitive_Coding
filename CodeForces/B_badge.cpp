#include<bits/stdc++.h>
using namespace std;

void addEdge (vector<int> adj[], int tail, int head)
{
	adj[tail].push_back(head);
}

int dfs(vector<int> adj[], int holes[], int i)
{
	holes[i]++;
	if (holes[i] == 2)
		return i;
	dfs(adj, holes, adj[i][0]);
}

int main()
{
    int n;cin>>n;
	vector<int> adj[n+1];
	int holes[n+1];
	for (int i = 1; i < n+1; ++i)
	{
		int p_i;cin>>p_i;
		addEdge(adj,i,p_i);
		holes[i] = 0;
	}
    for (int i = 1; i < n+1; ++i)
    {
    	cout << dfs(adj,holes,i) << " ";
    	for (int j = 1; j < n+1; ++j)
    	{
    		holes[j]=0;
    	}
    }
}
