#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
const int N = 1e5+7;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	ll sm = 0;
	for (int i = 0; i < n-1; ++i)
	{
		sm+=a[i];
	}
	if (sm>=a[n-1] && (sm+a[n-1])%2==0)
		cout<<"YES";
	else
		cout<<"NO";
}