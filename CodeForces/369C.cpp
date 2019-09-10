#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
const int N = 1e5+7;
int lvl[N],par[N];
vector<int> lvl2[N];
bool okay[N],okay2[N];
vector<pair<int,int> > pr;
vector<int> ans;
vector<int> adj[N];

void rtree(int rt)
{
	for(auto c : adj[rt])
	{
		if (c != par[rt])
			{par[c] = rt;
				lvl[c] = lvl[rt]+1;
				rtree(c);}
	}
}

void dfs(int src)
{
	okay[src] = true;
	okay2[src] = true;
	int temp = src;
	while(temp != 1 && !okay2[par[temp]])
	{
       temp = par[temp];
       okay[temp] = true;
       okay2[temp] = true;
	}
}

int main()
{
	for (int i = 0; i < N; ++i)
	{
	    okay[i] = 1;
	    okay2[i] = 0;
	}
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		int xi,yi,ti;cin>>xi>>yi>>ti;
		adj[xi].push_back(yi);
		adj[yi].push_back(xi);
		if (ti==2)
		{
			pr.push_back({xi,yi});
		}
	}
	lvl[1] = 1;
    rtree(1);
    for (int i = 1; i < n+1; ++i)
    {
    	lvl2[lvl[i]].push_back(i);
    }
    for (auto pair : pr)
    {
    	if (par[pair.first] == pair.second)
    	{
    		okay[pair.first] = false;
    	}
    	else
    	{
    		okay[pair.second] = false;
    	}
    }
    int l = 1;
    for (int i = 1; i < n+1; ++i)
    {
    	l = max(l,lvl[i]);
    }
    // for (int i = 1; i < n+1; ++i)
    // {
    // 	cout<<lvl[i]<<" ";
    // }
    while(l!=1)
    {
    	for(auto nd : lvl2[l])
    	{
    		if (!okay[nd])
    		{
    			dfs(nd);
    			ans.push_back(nd);
    		}
    	}
    	l--;
    }
    cout<<ans.size()<<endl;
    for (auto u : ans)
    {
    	cout<<u<<" ";
    }

}