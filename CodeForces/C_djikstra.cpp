#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long dist[101010];

int main()
{   
	ll INF = 1e18;
	int n;cin>>n;
	int m;cin>>m;
	vector<pair<int,int>> adj[n+1];
	vector<int> path[n+1];
	path[1].push_back(1);
	for (int i = 0; i < m; ++i)
	{
		int a;cin>>a;
		int b;cin>>b;
		int w;cin>>w;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
	bool proc[n+1];
    
    for (int i = 1; i < n+1; ++i)
    {
    	dist[i] = INF;
    	proc[i] = false;
    }
    dist[1] = 0;
    priority_queue<pair<int,int>> q;
    q.push({0,1});
    while(!q.empty())
    {
          int a = q.top().second; q.pop();
          if (proc[a]) continue;
          proc[a] = true;
          for (auto u : adj[a])
          {
          	int b = u.first;
          	int w = u.second;
          	if (dist[a] + w < dist[b])
          	{
          		dist[b] = dist[a] + w;
          		q.push({-dist[b],b});
          		path[b] = path[a];
          		path[b].push_back(b);
          	}
          }
    }
    int s = path[n].size();
    if (s==0)
    {
    	cout<<-1;
    }
    else
    {
    	for (int i = 0; i < s; ++i)
    {
    	cout<<path[n][i]<<" ";

}
}
}