#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long;

char grid[501][501];//[row][col]

int extra (int r1, int r2, int c1, int c2)
{
   int ex = 0;
  if (r1 > 1)
 { for (int c = c1; c < c2+1; ++c)
   {
   	if (grid[r1][c] == '.' && grid[r1-1][c] == '.')
   		ex++;
   }
 }

   if (c1 > 1)
 { for (int r = r1; r < r2+1; ++r)
   {
   	if (grid[r][c1] == '.' && grid[r][c1-1] == '.')
   		ex++;
   }
 }
   return ex;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h,w;cin>>h>>w;
	for (int r = 1; r < h+1; ++r)
	{
		for (int c = 1; c < w + 1; ++c)
		{
			cin>> grid[r][c]; // . or #
		}
	}
    
    int dp[501][501];
    
    dp[0][0]=0;
	for (int r = 1; r < h+1; ++r)
	{
		dp[r][0]=0;
		for (int c = 1; c < w + 1; ++c)
		{
			dp[0][c] = 0;
			dp[r][c] = dp[r][c-1] + dp[r-1][c] - dp[r-1][c-1];
			if (grid[r][c] == '.')
			{
				if (grid[r][c-1] == '.')
					dp[r][c]++;
				if (grid[r-1][c] == '.')
					dp[r][c]++;
			}
			//cout<<dp[r][c]<<" "; // . or #
		}
		//cout<<endl;
	}

    int q; cin>>q;
    int r1,c1,r2,c2;
    while(q--)
    {
    	cin>>r1>>c1>>r2>>c2;
    	cout<<dp[r2][c2]+dp[r1-1][c1-1]-dp[r2][c1-1]-dp[r1-1][c2]-extra(r1,r2,c1,c2)<<'\n';
    	//cout<<endl;
    }
    
}