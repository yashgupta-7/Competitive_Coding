#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int small = k+1;
	int big = 2*k+1;
	int r = n%big;
	int q = n/big;
    if (r >= k+1)
    {
    	cout<<q+1<<endl;
    	int curr = r - k;
    	while (curr <= n)
    	{
    		cout<<curr<<" ";
    		curr+=big;
    	}
    }
    else if (r == 0)
    {
    	cout<<q<<endl;
        int curr = k+1;
    	while (curr <= n)
    	{
    		cout<<curr<<" ";
    		curr+=big;
    	}
    }
    else
    {
    	cout<<q+1<<endl;
    	int curr = 1;
    	while (curr <= n)
    	{
    		cout<<curr<<" ";
    		curr+=big;
    	}
    }
}