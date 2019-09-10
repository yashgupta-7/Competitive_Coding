#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
const int N = 5e4+7;
vector<int> adj[N];
int par[N],dp[N][507];

void root_tree(int r)
{
	for (auto u : adj[r])
	{
		if (u != par[r])
		{
			par[u] = r;
			root_tree(u);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;cin>>n>>k;
	for (int i = 0; i < n-1; ++i)
	{
		int ai,bi;
		cin>>ai>>bi;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	root_tree(1);
	dp[1][0] = 1;
	for(int d = 0;d < k+1;d++)
	{
		if (d == 0)
        
		for(int i = 1;i<n+1;i++)
	    {
			if (d == 0)
			{dp[i][d] = 1;continue;} 
		    for (auto v : adj[i])
				{if (v != par[i])
					dp[i][d] += dp[v][d-1];}
	    }
	}
	int ans=0;
	for (int i = 1;i<n+1;i++)
	{
		for (auto v : adj[i])
			if (v != par[i])
				for (int x=1;x<k;x++)
					ans += dp[v][x-1]*(dp[i][k-x]-dp[v][k-x-1]);
	}
	for (int i = 1; i < n+1; ++i)
	{
		for (int d = 0;d < k;d++)
		{
			cout<<dp[i][k]<<" ";
		}
		cout<<'\n';
	}
	cout<<ans/2;

}
