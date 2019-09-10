#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
const int N = 1e5+7;
vector<pair<int,ll> > adj[N];
ll lvl[N],dp[N],par[N],a[N],pr[N];
vector<int> lvl2[N];

void root_tree(int rt)
{
    for (auto x : adj[rt])
    {
    	if (x.first != par[rt])
    		{par[x.first] = rt;
    			lvl[x.first] = lvl[rt]+1;
    			root_tree(x.first);}
    }
}

void dfs(int src)
{
	pr[src] = false;
	for (auto u : adj[src])
	{
		if (u.first != par[src])
			dfs(u.first);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	for (int i = 1; i < n+1; ++i)
	{
		cin>>a[i];
		pr[i] = true;
	}
	for (int i = 1; i < n; ++i)
	{
		int pi,ci;cin>>pi>>ci;
		adj[i+1].push_back({pi,ci});
		adj[pi].push_back({i+1,ci});
	}
	lvl[1]=1;
	root_tree(1);
	ll l = 1;
	for (int i = 1; i < n+1; ++i)
	{
		l = max(l,lvl[i]);
		lvl2[lvl[i]].push_back(i);
	}
	//cout<<l;
    dp[1] = 0;
	for (int j = 1;j <= l;j++)
	{
	for (auto i : lvl2[j])
	{
		for (auto u : adj[i])
		{
			if (u.first != par[i])
				dp[u.first] = max(dp[i]+u.second,u.second);
		}
	}
}
	int ans = 0;
	for (int i = 1; i < n+1; ++i)
	{
		//cout<<i<<" "<<dp[i]<<endl;
		if (dp[i] > a[i] && pr[i])
			dfs(i);
	}
	for (int i = 1; i < n+1; ++i)
	{
		//cout<<i<<" "<<dp[i]<<endl;
		if (!pr[i])
			ans++;
	}
    cout<<ans;

    
}