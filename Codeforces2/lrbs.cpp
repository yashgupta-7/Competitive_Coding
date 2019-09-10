#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
const int N = 1e7;
int dp[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;cin>>s;
	int n = s.length();
	dp[0]=1;
	rep(i,1,n-1){
        if (s[i] == '('){
             dp[i]=i+1;
        }
        else if (s[i] == ')'){
        	if (dp[i-1]>0 && s[dp[i-1]-1]=='('){
        		if (dp[i-1]>1){
        			dp[i]=dp[dp[i-1]-2];
        		}
        		else {
        			dp[i]=dp[i-1]-1;
        		}
        	}
        	else{
        		dp[i]=i+1;
        	}
        }
	}
	int mx=0;
	int nmx=0;
	// rep(j,0,n-1) cout<<dp[j]<<" ";
	// cout<<endl;
	rep(i,0,n-1){
        mx = max(mx,i-dp[i]+1);
	}
	rep(i,0,n-1){
		if (mx==i-dp[i]+1){
			nmx++;
		}
	}
	if (mx) cout<<mx<<" "<<nmx;
	else cout<<0<<" "<<1;
}