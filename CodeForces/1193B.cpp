#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> ip;
# define INF 2000000000


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
    for (int i = 2; i < n+1; ++i)
    {
    	int pi;
    	adj[i].push_back(pi);
    	adj[pi].push_back(i);
    	adj2[pi].push_back(i);
    }
    for (int i = 1; i < m+1; ++i)
    {
    	cin>>v[j]>>d[j]>>w[j];
    }
    dp[i] = dp[u]+dp[v]
}