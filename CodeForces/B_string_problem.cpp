#include<bits/stdc++.h>
using namespace std;
const int INF = 10e8+7;
const int N = 27;
int adj[27][27];
int dist[27][27];

string to_letter(int n)
{
	 string s = "a";
	 s[0] = n + 96;
	
	return s;
}

pair<int,int> ncd(int src1,int src2)
{
     int md = INF;
     int ans = -1;
     for (int i = 1; i < N; ++i)
     {
     	if (md > dist[src1][i]+dist[src2][i])
     		{
     			ans = i;
     			md = dist[src1][i]+dist[src2][i];
     		}
     }
     return {ans,md};
}

int main()
{
	for (int i = 1;i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			adj[i][j] = INF;
		}
	}
	string s;cin>>s;
	string t;cin>>t;
	int n;cin>>n;
	for (int i = 0; i < n; ++i)
	{
		char ul,vl;cin>>ul>>vl;
		int u = ul - 'a' + 1;
		int v = vl - 'a' + 1;
	    int w;cin>>w;
		adj[u][v] = min(w,adj[u][v]);
	}

	if (s.size() != t.size())
	{
		cout<<-1;
		return 0;
	}

	for (int i = 1 ;i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
		   if (i==j) dist[i][j] = 0;
		   else dist[i][j] = adj[i][j];
		}
	}
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			for (int k = 1; k < N; ++k)
			{
				dist[k][j] = min(dist[k][j],dist[k][i]+dist[i][j]);
			}
		}
	}

	int cost = 0;
	string final;
	for (int i = 0; i < s.size(); ++i)
	{
		pair<int,int> p = ncd (s[i]-'a'+1,t[i] - 'a' +1);
		if (p.second > 10e7)
		{
			cout<<-1;
			return 0;
		}
		cost += p.second;
		final += to_letter(p.first);
	}
    if (cost > 10e7)
    	cout<<-1;
    else
    {
    	cout<<cost<<'\n';
        cout<<final;
    }
}