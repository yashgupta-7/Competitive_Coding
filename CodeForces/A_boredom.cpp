#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
#define ll long long
ll freq[100005];
ll dp1[100005],dp2[100005];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;cin>>n;
    ll arr[n+1];
    ll ans=0;
    for (int i = 1; i < n+1; ++i)
    {
    	cin>>arr[i];
    	freq[arr[i]]++;
    }
    ll i=1;
    for( i=1;i<100005;i++){
    	if(i!=1)
    	dp1[i]=i*freq[i]+max(dp1[i-2],dp2[i-2]);
    	else
    	dp1[i]=i*freq[i];
    	dp2[i]=dp1[i-1];
    }
i--;
cout<<max(dp1[i],dp2[i])<<endl;


}
