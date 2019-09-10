#include<iostream>
#include<iomanip>
#include<math.h>
#define ll long long
const int N=1e6+5
ll dp[N][2],a[N];
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][0]=1e17;
	dp[0][1]=0;
	for(int i=1;i<=n;i++){
		ll one=abs(1-a[i]);
		ll mi=abs(-1-a[i]);
		dp[i][0]=min(mi+dp[i-1][1],one+dp[i-1][0]);
		dp[i][1]=min(one+dp[i-1][1],mi+dp[i-1][0]);
	}
	cout<<dp[n][1]<<endl;
}