#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,x;cin>>n>>k>>x;
    ll a[n+1];
    ll mx = -1*INF;
    ll mx_id;
    for (int i = 1; i < n+1; ++i)
    {
    	cin>>a[i];
    	// if (a[i] >= mx)
    	// {
    	// 	mx_id = i;
    	// 	mx = a[i];
    	// }
    }

    ll ans1=0;
    ll left[n+1];left[0]=0;
    for (int i = 1; i < n+1; ++i)
    {
    	ans1=ans1|a[i];
        left[i]=ans1;
    }
    
    ll ans2=0;
    ll right[n+2];right[0]=0;right[n+1]=0;
    for (int i = n; i > 0; --i)
    {
    	ans2=ans2|a[i];
        right[i]=ans2;
    }

    ll ansf = 0;
    for (int j = 1; j < n+1; ++j)
    {
    ll ans=0;
    
            ans = ans|left[j-1];
    		ans = ans|a[j]*(int)pow(x,k);
    	    ans = ans|right[j+1];
   
   // cout<<ans<<endl;
    ansf = max(ansf,ans);
	}
    cout<<ansf;
}
