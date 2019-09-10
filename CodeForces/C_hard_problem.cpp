#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long 

string reverse(string str) 
{  
   string sr="";
   for (ll i=str.length()-1; i>=0; i--) 
      sr += str[i]; 
   return sr; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	ll c[n+1]; // 1 to n
	for (int i = 1; i < n+1; ++i)
	{
		cin>>c[i];
	}
    string s[n+1]; // 1 to n
    for (int i = 1; i < n+1; ++i)
    {
    	cin>>s[i];
    }
    
    bool br = false;
    ll dp[n+1][2];
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (ll i = 1; i < n+1; ++i)
    {
    	ll j = 0;//not rev
    	if (s[i] >= s[i-1] && s[i] >= reverse(s[i-1]))
    		dp[i][j] = min(dp[i-1][0],dp[i-1][1]);
    	else if (s[i] >= s[i-1])
    		dp[i][j] = dp[i-1][0];
    	else if (s[i] >= reverse(s[i-1]))
    		dp[i][j] = dp[i-1][1];
    	else
    		dp[i][j] = INF;
    	j = 1; // rev
    	if (reverse(s[i]) >= s[i-1] && reverse(s[i]) >= reverse(s[i-1]))
    		dp[i][j] = min(dp[i-1][0],dp[i-1][1]) + c[i];
    	else if (reverse(s[i]) >= s[i-1])
    		dp[i][j] = dp[i-1][0] + c[i];
    	else if (reverse(s[i]) >= reverse(s[i-1]))
    		dp[i][j] = dp[i-1][1] + c[i];
    	else 
    		dp[i][j] = INF;
    	// {
     //       br? = true;
     //       break;
    	// }
    }
    //if br? cout<<-1;
    //else 
    // for (int i = 1; i < n+1; ++i)
    // 	{
    // 		cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    // 	}	
    
    ll ans = min(dp[n][0],dp[n][1]);;
    if (ans == INF)
    	cout<<-1;
    else cout<<ans;

}