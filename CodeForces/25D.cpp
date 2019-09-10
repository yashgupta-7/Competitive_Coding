#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
const int N = 1007;
int adj[N][N];
int par[N];
bool disc[N],st[N];
vector<pair<int, int> > rem;
int n;
vector<int> v;

void dfs(int src1,int src,int e)
{
	par[src]=src1;
	disc[src]=1;
	//cout<<src<<" "<<src1<<endl;
	for (int i=1;i<n+1;i++)
	{
		if (adj[src][i] && i!=e)
			{
			  if (!disc[i])
				{par[i]=src1;dfs(src1,i,src);}
			  else
				{
					adj[src][i]=0;
					adj[i][src]=0;
					rem.push_back({src,i});
				}
	        }
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		int ai,bi;cin>>ai>>bi;
		adj[ai][bi]=1;
		adj[bi][ai]=1;
	}
	
	for (int i = 1; i < n+1; ++i)
	{
		if (!disc[i])
			{dfs(i,i,0);}
	}

	// for (int i = 1; i < n+1; ++i)
	// {
	// 	cout<<par[i]<<" ";
	// }
	// cout<<endl;

	for (int i=1;i<n+1;++i)
	{
		st[par[i]]=1;
	}

	for (int i = 1; i < n+1; ++i)
	{
		if (st[i])
			v.push_back(i);
	}
    
    int t = v.size()-1;
    cout<<t<<endl;
    for (int i = 0; i < t; ++i)
    {
    	const int b = i;
    	cout<<rem[i].first<<" "<<rem[i].second<<" "<<v[i]<<" "<<v[i+1]<<'\n';
    }
}