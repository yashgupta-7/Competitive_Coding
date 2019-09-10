#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
const int N = 10e7;
int res[10][10],dp[10][10][100];
#define int long long

main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int x=0;x<10;x++)
	{
		for (int y=0;y<10;y++)
		{
			for(int i=0;i<100;i++)
			{
				dp[x][y][i]=  INF;
			}
		}
	}

	for (int x=0;x<10;x++)
	{
		for (int y=0;y<10;y++)
		
	{		dp[x][y][0]=0;
			for(int i=1;i<100;i++)
				{
				if (i>=x && i>=y)
					dp[x][y][i]=min(dp[x][y][i-x],dp[x][y][i-y])+1;
				else if (i>=x && i<y)
					dp[x][y][i]=dp[x][y][i-x]+1;
				else if (i<x && i>=y)
					dp[x][y][i]=dp[x][y][i-y]+1;
				}
		}
	}

	// int x=2,y=3;
	// for (int k=0;k<100;k++)
	// 	{
	// 		cout<<dp[x][y][k]<<'\n';
	// 	}
	for (int x=0;x<10;x++)
		{
			for (int y=0;y<10;y++)
			{
				for(int inc=1;inc<10;inc++)
				{
					int temp = INF;
					for(int l=0;l<10;l++)
					{
					ll one=1;
					temp = min(temp,dp[x][y][inc+10*l]-one);
					}
					dp[x][y][inc]=temp;
				}
            }
        }


	string s;cin>>s;
	for(int j=0;j<s.size()-1;j++)
	{
		int inc;
		if (s[j]=='0' && s[j+1]!='0')
			inc = s[j+1] - '0';
		else
			inc=s[j+1]-s[j]+10;
		//cout<<inc<<endl;
		for (int x=0;x<10;x++)
		{
			for (int y=0;y<10;y++)
			{
				//cout<<temp;
				res[x][y]+=dp[x][y][inc];
			}
		}

	}

	for (int x=0;x<10;x++)
	{
			for (int y=0;y<10;y++)
			{
				if (res[x][y] > N)
                   cout<<-1<<" "; 
				else
					cout<<res[x][y]<<" ";
			}
		cout<<endl;
	}

}