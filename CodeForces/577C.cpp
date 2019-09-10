#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 5000000000
const int N = 2e5+7;
#define int long long 
int a[N];

 main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int id = n/2;
	int m = 1;
	a[n] = INF;
	while(k>0 && id+m <= n)
	{
		if (k <= (a[id+m]-a[id])*m)
			{a[id] += k/m;
				break;}
		else 
		{
			k -= (a[id+m]-a[id])*m;
            a[id]=a[id+m];
		}
		m++;
	} 
	cout<<a[id];     
}