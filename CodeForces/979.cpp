#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
const int N = 3e5+7;
vector<int> adj[N];
int par[N];
int cnt = 0;
int root;

void root_tree(int r)
{
	for (auto c : adj[r])
	{
		if (c!= par[r])
			{par[c] = r;
		   root_tree(c);}
	}
}

void dfs(int src,int e)
{
    cnt++;
    for (auto c : adj[src])
    {
    	if (c!=e && c!=root)
    	{
            dfs(c,src);
    	}
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;cin>>n;
	ll x,y;cin>>x>>y;
	
	for (int i = 0; i < n-1; ++i)
	{
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
    }
    root = x;
    root_tree(root);
    // for (int i = 1; i < n+1; ++i)
    // {
    // 	cout<<par[i]<<" ";
    // }
    // cout<<endl;
    dfs(y,0);
    ll n1 = cnt;
    //cout<<n1<<endl;
    cnt = 0;
    dfs(y,par[y]);
    ll n2 = cnt;
    //cout<<n2<<endl;
    ll ip = n2*(n-n1);
    cout<<n*(n-1)-ip;
}