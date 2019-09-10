#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
vector<int> nc2,res;

int mult (int x,int y,int z)
{
	return (x*y*(y-1)*z)/2;
}

int main()
{
	int x=1e5;
	nc2.push_back(0);
	for (int i = 1; i < x; ++i)
	{
		nc2.push_back(i*(i-1)/2);
	}
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	for (int i = 0; i < t; ++i)
	{
	int n;cin>>n;
	
	while(n!=0)
	{
		vector<int>::iterator ind = lower_bound(nc2.begin(),nc2.end(),n);
		int y=ind-nc2.begin();
		res.push_back(y);
        n=n-nc2[y];
	}
	cout<<1;
	for(auto j : res)
	{
		for (int i = 0; i < j; ++i)
		{
			cout<<3;
		}
		cout<<7;
	}
	}
        
}