#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
const int N = 1007;
#define int long long
int m;
string s[N];
int a[N];
int mx[N][5];

main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;cin>>n>>m;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
	    for (int j = 0; j < m; ++j)
	    {
	    	int x = s[i][j] - 'A';
	    	mx[j][x]++;
	    }
	}
	int ans=0;
	// for (int i = 0; i < m; ++i)
	// {
	// 	for (int j = 0; j < 5; ++j)
	// 	{
	// 		cout<<mx[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	for (int i = 0; i < m; ++i)
	{
		cin>>a[m];
		int id = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (mx[i][j] > mx[i][id])
			{
				id = j;
			}
		}
		ans += mx[i][id]*a[m];
	}
	cout<<ans;
	
}