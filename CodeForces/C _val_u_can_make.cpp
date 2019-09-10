#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long;

int c[505];
bool dp[505][505][505];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;cin>>n>>k;
    for (int i = 1; i < n+1; ++i)
    {
    	cin>>c[i];
    }
    
    for (int i = 1; i < n+1; ++i)
    {
    	for (int j= 0; j < k+1; ++j)
    	{
    		for (int x = 0; x < j+1; ++x)
    		{
    			dp[i][j][x] = false;
    		}
    	}
    }

    for (int i = 0; i < n+1; ++i)
    {
    	dp[i][0][0] = true;
    }

    for (int i = 1; i < n+1; ++i)
    {
    	for (int j= 0; j < k+1; ++j)
    	{
    		for (int x = 0; x < j+1; ++x)
    		{
    			
    			if (x >= c[i])
    				dp[i][j][x] = dp[i-1][j][x] || dp[i-1][j-c[i]][x] || dp[i-1][j-c[i]][x-c[i]];
    			else if (j >= c[i])
    				dp[i][j][x] = dp[i-1][j][x] || dp[i-1][j-c[i]][x];
    			else
    				dp[i][j][x] = dp[i-1][j][x];
    		}
    	}
    }

    for (int i = 1; i < n+1; ++i)
    {
    	for (int j= 0; j < k+1; ++j)
    	{
    		if dp[i][k][j]
    		   cout<<j<<" ";
    	}
    }

}