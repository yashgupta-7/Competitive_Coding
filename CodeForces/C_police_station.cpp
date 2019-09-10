#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define INF 2000000000
const int N = 105;
int dist[N];
int dist2[N];
ll nsps[N];
ll nspv[N];
int num = 0;
int n,m;
vector<int> adj[105];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    
    
    
    for (int i = 1; i < n+1; ++i)
    {
    	dist[i] = INF;
    	dist2[i] = INF;
    	nsps[i] = 0;
    	nspv[i] = 0;
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    nsps[1] = 1;
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto b : adj[a])
		{
			if (dist[b] > dist[a]+1)
			{
				q.push(b);
				dist[b] = dist[a] + 1;
				nsps[b] = nsps[a];

			}
			else if (dist[b] == dist[a]+1)
			{
				//q.push(b);
				dist[b] = dist[a]+1;
				nsps[b] += nsps[a];
			}
		}
	}

	queue<int> q2;
    q2.push(n);
    nspv[n] = 1;
    dist2[n] = 0;
	while(!q2.empty())
	{
		int a = q2.front();
		q2.pop();
		for (auto b : adj[a])
		{
			if (dist2[b] > dist2[a]+1)
			{
				q2.push(b);
				dist2[b] = dist2[a] + 1;
				nspv[b] = nspv[a];
			}
			else if (dist2[b] == dist2[a]+1)
			{
				//q2.push(b);
				dist2[b] = dist2[a]+1;
				nspv[b] += nspv[a];
			}
		}
	}

    for (int i = 1; i < n+1; ++i)
    {
    	//cout<<nsps[i]<<" "<<nspv[i]<<'\n';

    }
    ll mx = -1;
    for (int i = 2; i < n; ++i)
    {
    	if (dist[i]+dist2[i] == dist[n])
    		mx = max(mx,nsps[i]*nspv[i]*2);
    	//cout<<mx<<'\n';
    }
    mx=max(mx,nsps[1]*nspv[1]);
    mx=max(mx,nsps[n]*nspv[n]);
    long double ans = 1.0*mx/nsps[n];
    cout<<setprecision(30)<<ans<<endl;

}
