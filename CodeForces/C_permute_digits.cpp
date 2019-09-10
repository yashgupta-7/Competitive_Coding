#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	string a;
	string b;
	cin>>a>>b;
	int sa = a.size();
	int sb = b.size();
	sort(a.begin(),a.end());
	// if (sa < sb)
	// {
	// 	cout<<stoll(a.reverse());
	// }
	//else
	{
        for (int i = 0; i < sa; ++i)
        {
        	for (int j = i+1; j < sa; ++j)
        	{
        		string t = a;
        		swap(t[i],t[j]);
        		sort(t.begin()+i+1, t.end());
        		if (stoll(t) <= stoll(b))
        			swap(a[i],a[j]);
        	}
        }
	}
	cout<<a;
}