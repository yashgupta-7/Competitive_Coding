#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
const int N = 1e6;
int dp[N],dp2[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;cin>>s;
	int n = s.length();
	dp[0]=1;
	dp2[0]=0;
	rep(i,1,n-1){
        if (s[i] == '('){
              dp[i] = i+1;
              dp2[i]=0;
        }
        else if (s[i] == ')'){
            if (s[dp[i-1]-1] == '(' && dp[i-1] > 1){
            	dp[i] = dp[dp[i-1]-2];
            	dp2[i] = dp2[i-1]+dp2[dp[i-1]-2];
            }
            else if (s[dp[i-1]-1] == '('){
            	dp[i]=dp[i-1]-1;
            	dp2[i] = dp2[i-1];
            }
            else {
            	dp[i]=i+1;
        	    dp2[i]=0;
            }
        }
        else if (s[i] == '['){
        	dp[i]=i+1;
        	dp2[i]=0;
        }
        else if (s[i] == ']'){
            if (s[dp[i-1]-1] == '[' && dp[i-1] > 1){
            	dp[i] = dp[dp[i-1]-2];
            	dp2[i] = 1+dp2[i-1]+dp2[dp[i-1]-2];
            }
            else if (s[dp[i-1]-1] == '['){
            	dp[i]=dp[i-1]-1;
            	dp2[i] = 1+dp2[i-1];
            }
            else {
            	dp[i]=i+1;
        	    dp2[i]=0;
            }
        }
	}

	// rep(i,0,n-1) cout<<dp[i]<<" ";
	// cout<<endl;
 //    rep(i,0,n-1) cout<<dp2[i]<<" ";
 //    cout<<endl;
	int mx = 0;
	int id = -1;
	rep(i,0,n-1) {
		if (mx < dp2[i]){
			id = i;
			mx = dp2[i];
		}
	}
	cout<<mx<<endl;
	if (mx) {
	rep(j,dp[id],id){
		cout<<s[j];
	}}

}