#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,I;cin>>n>>I;
	int bits = I*8;
	int k = bits/n;
	int K = pow(2,min(k,30));
	int a[n+1];
	for (int i = 1; i < n+1; ++i)
	{
		cin>>a[i];
		
		
	}
	int s[n+1];
	for (int i = 0; i < n+1; ++i)
	{
	    s[i] = 0;
	}
	s[1] = 1;
	int c = 2;
	sort(a+1,a+n+1);
	for (int i = 2; i < n+1; ++i)
	{
		if (a[i] != a[i-1])
			{
				s[c] = i;
				c++;
			}
	}
	int mx = 1;
	for (int i = 0; i < n+1-K; ++i)
	{
		if (s[i+K] - s[i] > mx)
			mx = s[i+K] - s[i];
	}
	if (c-1 <= K)
		cout<<0;
	else
		cout<<n-mx;

    
}