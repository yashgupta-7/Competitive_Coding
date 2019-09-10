#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long 


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll k;cin>>k;
	string str;cin>>str;ll l = str.size();
	ll n_ss[k+1][l+1];
	ll n_z[l+1];int cz = 0;int n_o = 0;
	for (int i = 0; i < l; ++i)
	{
		if (str[i] == '1') 
	    {	
	    	n_z[n_o] = cz;//between jth one and j+1th one
	    	n_o++;
	    	cz=0;
	    }
		else cz++;
	}
	
	for (int i = 0; i < l+1; ++i)
	{
		cout<<n_z[i]<<" ";
	}
	cout<<endl;

	n_o=0;

	if (str[1] == '1')
	n_ss[1][1] =  1;
    else n_ss[1][1] =  0;

	for (ll j = 2; j < k+1; ++j)
	{
		n_ss[1][j] = 0;
	}
	for (ll j = 0; j < k+1; ++j)
	{
		n_ss[0][j] = 0;
	  for (ll i = 2; i < l+1; ++i)
	
	{
		if (str[i] == '0')
			{
				if (n_o >= j)
					n_ss[i][j] = n_ss[i-1][j] + 1 + n_z[n_o-j];
				else
					n_ss[i][j] = 0;
			}
		else
			{
				if (n_o >= j-1)
					n_ss[i][j] = n_ss[i-1][j-1] + 1 + n_z[n_o-j+1];
				else
					n_ss[i][j] = 0;
				n_o++;
			}
	}
	}
	for (ll j = 0; j < k+1; ++j)
	{
		for (ll i = 1; i < l+1; ++i)
		{
			cout<<n_ss[i][j]<<" ";
		}
		cout<<endl;
	}
}
