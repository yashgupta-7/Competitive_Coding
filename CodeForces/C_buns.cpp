#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin>>n;
	int m;cin>>m;
	int a[m+1],b[m+1],c[m+1],d[m+!1];
	a[0] = 0;
	b[0] = 0;
	cin>>c[0]>>d[0];
	for (int i = 1; i < m+1; ++i)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	vector<int> cost;
	vector<int> wt;
	int lim1 = n/c[0];
	for (int i = 0; i < lim1; ++i)
	{
		cost.push_back(c[0]);
		wt.push_back(d[0]);
	}
	for (int i = 1; i < m+1; ++i)
	{
		int lim2 = a[i]/b[i];
		for (int j = 0; j < lim2; ++j)
		{
			cost.push_back(c[i]);
		    wt.push_back(d[i]);
		}
	}
	int size = cost.size();
	int dp[n+1][size+1];

	for (int w = 0; w < n+1; ++w)
	{
		for (int i = 0; i < size+1; ++i)
		{
			if (i==0 || w==0)
				dp[w][i] = 0;
			else if (w >= cost[i-1])
		         dp[w][i] = max(dp[w-cost[i-1]][i-1]+wt[i-1],dp[w][i-1]);
	        else
		         dp[w][i] = dp[w][i-1];
		}
	}

	// for (int i = 0; i < size; ++i)
	// {
	//    cout<<cost[i]<<" "<<wt[i]<<'\n';
	// }
	cout<<dp[n][size];
	
}