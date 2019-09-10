#include<bits/stdc++.h>
using namespace std;
const int N = 10e5;
vector<pair<int,int>> adj[N];
int dist[N];

void bfs01(int src)
{
	deque <int> q;
	dist[src] = 0;
	q.push_back(src);
	while(!q.empty())
	{
		int a = q.front();
		q.pop_front();
		for (auto b : adj[a])
		{
			if (b.second == 1)
			{
				if (dist[b.first] > dist[a] + 1)
			{
				dist[b.first] = dist[a] + 1;
				q.push_back(b.first);
			}
			}
			else if (b.second == 0)
			{
				if (dist[b.first] > dist[a])
			{
				dist[b.first] = dist[a];
				q.push_front(b.first);
			}
			}
		}
	} 
}



int main()
{
   for (int i = 0; i <N; ++i)
   {
   	 dist[N] = N;
   }
   int n;cin>>n;
   int m;cin>>m;
   for (int i = 0; i < m; ++i)
   {
   	  int a,b,w;cin>>a>>b>>w;
      adj[a].push_back(make_pair(b,w));
      adj[b].push_back(make_pair(a,w));
   }
   bfs01(0);
   for (int i = 0; i < n; ++i)
   {
   	 cout<<dist[i]<<'\n';
   }

}