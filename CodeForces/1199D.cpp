#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
int a[200005],t[200005],d[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	for (int i = 1; i < n+1; ++i)
    {
    	cin>>a[i];
    	t[i] = 1;
    }
    int q;cin>>q;
    for (int i = 1; i < q+1; ++i)
    {
    	int p,c,x;
    	cin>>c;
    	if (c == 1)
    	{
           cin>>p>>x;
           a[p] = x;t[p] = i;
           d[i] = -1*INF;
    	}
    	else if (c == 2)
    	{
           cin>>x;
           d[i] = x;
    	}
    }
    for (int i = q-1; i > 0; --i)
    {
    	d[i] = max(d[i],d[i+1]);
    	//cout<<d[i]<<" ";
    }
    //cout<<'\n';
    for (int i = 1; i < n+1; ++i)
    {
    	cout<<max(a[i],d[t[i]])<<" ";
    }

}