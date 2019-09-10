#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
// ios::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);

int main()
{
	int n;cin>>n;
	string str;cin>>str;
	int arr1[n];
	int arr2[2*n+1];
	for (int i = 0; i < 2*n; ++i)
	{
		arr2[i] = INF;
	}
	arr2[n]=0;
	int diff = 0; //1-0
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '1') diff++;else diff--;
		arr1[i]=diff;
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<arr1[i]<<endl;
	// }
	int maxlen = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr2[arr1[i]+n] == INF)
			arr2[arr1[i]+n] = i+1;
		else
			maxlen = max(maxlen,i-arr2[arr1[i]+n]+1);
	}
	cout<<maxlen;
}
