#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
int res;
const int N = 3e5+7;
int dp[N][3];
int a[N],par[N];
vector<int> adj[N];

pair<int,int> dfs(int src,int e)
{
	int n1,n2;
	n1=0;n2=0;
    for (auto c : adj[src])
    {
    	if (c!=e)
    	{
    		par[c]=src;
    		pair<int,int> p = dfs(c,src);
    		n1 += p.first;
    		n2 += p.second;
    	}
    }
    if (a[src] == 1) n1++;
    else if (a[src] == 2) n2++;
    dp[src][1] = n1;
    dp[src][2] = n2;
    return {n1,n2};
}
void dfs2(int src,int e)
{
	for(auto c : adj[src])
	{
		if (c!=e)
		{int n11 = dp[c][1];
		int n21 = dp[c][2];
		int n12	= dp[1][1]-n11;
		int n22 = dp[1][2]-n21;
		if( (n11==0 && n22==0) || (n21==0 && n12==0))
		{
			res++;
		}
		dfs2(c,src);}
	}
}

int main()
{
	res=0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	for (int i = 1; i < n+1; ++i)
	{
	    cin>>a[i];
	}
	for (int i = 0; i < n-1; ++i)
	{
		int vi,ui;cin>>vi>>ui;
		adj[vi].push_back(ui);
		adj[ui].push_back(vi);
	}
    pair<int,int> tot = dfs(1,0);
    dfs2(1,0);
    // for(int i=1;i<n+1;i++ )
    // {
    // 	for (int j=1;j<3;j++)
    // 	{
    // 		cout<<dp[i][j]<<" ";
    // 	}
    // 	cout<<'\n';
    // }
    
    cout<<res;
    
}