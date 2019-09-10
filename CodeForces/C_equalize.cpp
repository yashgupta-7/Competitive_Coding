#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long;

// int ms (string a, string b)
// {
//   if (a.size() == 0)
//   	return 0;
//   if (a[0] == b[0])
//   {
//   	return ms(a.substr(1),b.substr(1));
//   }
//   if (a.size() == 1 && )
  
// }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	string a,b;
	cin>>a>>b;
	int op = 0;
    for (int i = 0; i < n; ++i)
    {
    	if (a[i] == b[i]) continue;
    	if (i == n-1) op++;
    	else if (a[i] == b[i+1] && b[i] == a[i+1])
    	{
    		i++;
    		op++;
    	}
    	else
    	{
    		op++;
    	}
    }
    cout<< op;

}