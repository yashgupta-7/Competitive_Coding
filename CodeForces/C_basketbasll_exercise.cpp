#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int n;cin>>n;
	ll f[n+1];
	ll s[n+1];
	for (int i = 1; i < n+1; ++i)
	{
		cin>>f[i];
	}
	for (int i = 1; i < n+1; ++i)
	{
		cin>>s[i];
	}
	ll dpf[n+1];
	ll dps[n+1];
	dpf[1]=f[1];
	dps[1]=s[1];
	if (n > 1)
	{
	dpf[2]=s[1]+f[2];
	dps[2]=f[1]+s[2];
	for (int i = 3; i < n+1; ++i)
	{
		dpf[i] = max(dps[i-1] + f[i],max(dpf[i-2],dps[i-2])+f[i]);
		dps[i] = max(dpf[i-1] + s[i],max(dps[i-2],dpf[i-2])+s[i]);
	}
    }
 	cout<<max(dps[n],dpf[n]);

}