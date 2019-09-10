#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> ip;
# define INF 2000000000
const int N = 2e5+7;
int bol[N],dp1[N],dp2[N],par[N];
vector<int> adj1[N],adj3[N],v;


void root_tree(int r)
{
	for (auto u : adj1[r])
	{
		if (u!=par[r])
		{
			par[u]=r;
			bol[u]=1;
			root_tree(u);
		}
	}
	for (auto u : adj3[r])
	{
		if (u!=par[r])
		{
			par[u]=r;
			bol[u]=-1;
			root_tree(u);
		}
	}
}

int dfs1(int node)
{
   int ans=0;
   for (auto c : adj1[node])
   {
   	if (c!=par[node])
   		ans += dfs1(c);
   }
   for (auto c : adj3[node])
   {
   	if (c!=par[node])
   		ans += dfs1(c)+1;
   }
   dp1[node]=ans;
   return ans;
}

int dfs2(int node)
{
	if (node==1)
	{	dp2[1]=dp1[1];
	    return dp1[1];     }
	else if (!dp2[node])
	{
		int res=0;
		res = bol[node]+dfs2(par[node]);
		dp2[node]=res;
		return dp2[node];
	}
	else 
	{
		return dp2[node];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		int si,ti;
		cin>>si>>ti;
		adj1[si].push_back(ti);
		// adj2[si].push_back(ti);
		// adj2[ti].push_back(si);
		adj3[ti].push_back(si);
	}
	par[1]=0;
	root_tree(1);
	dfs1(1);
	
	// for (int i = 1; i < n+1; ++i)
	// {
	// 	cout<<dp1[i]<<" ";
	// }
	// cout<<endl;

	int an=INF;
	for (int i = 1; i < n+1; ++i)
	{
			an = min(an,dfs2(i));
	}

	// for (int i = 1; i < n+1; ++i)
	// {
	// 	cout<<dp2[i]<<" ";
	// }
 //    cout<<endl;

	for (int i = 1; i < n+1; ++i)
	{
		if (dp2[i] == an)
			v.push_back(i);
	}
	cout<<an<<endl;
	for (auto no : v)
	{
		cout<<no<<" ";
	}

}