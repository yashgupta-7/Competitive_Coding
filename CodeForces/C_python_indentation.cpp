#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int B=5005;
int sum[B][B],dp[B][B];//st,in


int main()
{   
	ll m = 1000000007;
	int N;cin>>N;
	char st[N+1];
	for (int i = 1; i < N+1; ++i)
	{
		cin>>st[i];
	}
    for (int i = 0; i < N+1; ++i)
    {
    	for (int j = 0; j < N+1; ++j)
    	{
    		dp[i][j] = 0;
    		sum[i][j]=0;
    	}
    }
    dp[0][0] = 1;
    dp[1][0] = 1;
    sum[1][0]=1;
    for(int i=1;i<=N;i++)
    	sum[1][i]=(sum[1][i-1]+dp[1][i])%m;
    
    for (int stat = 2; stat < N+1; ++stat)
    {
    	for (int in = 0; in < N+1; ++in)
    	{
    		if (st[stat-1] == 's')
                {
                	ll res = 0;
                		if(in!=0)
                		res+=(sum[stat-1][N]-sum[stat-1][in-1])%m;
                		else
                			res+=sum[stat-1][N];
                		res = res%m;
                	
                	dp[stat][in] = res;
                }
             else if (st[stat-1] == 'f')
             {
             	if (in>0)
             		dp[stat][in] = dp[stat-1][in-1];
             	else 
             		dp[stat][in] = 0;
             }
    	}
    	sum[stat][0]=dp[stat][0];
    	for(int i=1;i<=N;i++)
    		sum[stat][i]=(sum[stat][i-1]+dp[stat][i])%m;
    }
    int ans = 0;
    for (int i = 0; i < N+1; ++i)
    {
       ans+=dp[N][i];
       ans = ans%m;
    }
    cout<<(ans+m)%m<<endl;
}
    
	  
