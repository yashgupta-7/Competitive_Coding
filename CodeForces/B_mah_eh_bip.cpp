#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long

ll color[100005]; //1 nd 2
bool found[100005];


ll cc(ll clr)
{
	if (clr == 1) return 2;
	else if (clr == 2) return 1;
}

void dfs(vector<ll> adj[], ll src, ll clr)
{
   found[src] = true;
   color[src] = clr;
   for (auto v : adj[src])
   {
        if (!found[v])
        	dfs(adj, v, cc(clr));
   }
   return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (ll i = 1; i < 100005; ++i)
{
	color[i] = 0; // uncolored
	found[i] = false;
}


	ll n;cin>>n;
	ll u,v;
	vector<ll> adj[n+1];//1 to n
	for (ll i = 0; i < n-1; ++i)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(adj,1,1);

	ll cl_1=0;
	for (ll i = 1; i < n+1; ++i)
	{
		//cout<<color[i]<<" ";
		if (color[i] == 1) cl_1++;
	}

    cout<< cl_1*(n-cl_1) - n + 1;

}