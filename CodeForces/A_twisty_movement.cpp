#include<bits/stdc++.h>
using namespace std;
#define ll long long

int lis(int arr[],int l,int r)
{
	int dp[r+1];
	dp[r]=1;
	for (int i = r-1; i >= l; --i)
	{
		int ans = 0;
		for (int j = i+1; j < r+1; ++j)
		{
			if (arr[j] >= arr[i])
				ans = max(ans,dp[j]);
			//cout<<ans;
		}
		dp[i]=ans+1;
	}
	int res = 0;
	for (int i = l; i < r+1; ++i)
	{
		res = max(res,dp[i]);
		//cout<<dp[i];
	}
	return res;
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   int st = 1;
   vector<int> v ;
   int acc = 0;
   for (int i = 0; i < n; ++i)
   {
   	cin>>a[i];
   	// if (a[i] == 1)
   	// {
   	// 	if (st == 1)
   	// 	{
   	// 		acc++;
   	// 	}
   	// 	else if (st == 2)
   	// 	{
   	// 		v.push_back(acc);
   	// 		acc = 1;
   	// 		st = 1;
   	// 	}
   	// }
   	// else if (a[i] == 2)
   	// {
   	// 	if (st == 1)
   	// 	{
   	// 		v.push_back(acc);
   	// 		acc = 1;
   	// 		st = 2;
   	// 	}
   	// 	else if (st == 2)
   	// 	{
   	// 		acc++;
   	// 	}
   	// }
   }
   //v.push_back(acc);
   
   //cout<<lis(a,n);
   int res = 0;
   for (int i = 1; i < n; ++i)
   {
   	res = max(res,lis(a,0,i-1)+lis(a,i,n-1));
   }
   cout<<res;
}

   //  for (auto x : v)
   // {
   // cout<<x<<'\n';
   // }
   // int ans = 0;
   // if (v.size() == 1)
   // {
   // 	ans = v[0];
   // }
   // else if (v.size() == 2)
   // {
   // 	ans = v[0] + v[1];
   // }
   // else if (v.size() == 3)
   // {
   // 	ans = v[0] + v[1] + v[2];
   // }
   // else if (v.size() > 3)
   // {
   // 	ans = 0;
   // 	for (int i = 3; i < v.size(); i+=2)
   // 	{
   // 		ans = max(ans,v[i-3]+v[i-2]+v[i-1]+v[i]);
   // 	}
   // }
   // cout<<ans;
   
