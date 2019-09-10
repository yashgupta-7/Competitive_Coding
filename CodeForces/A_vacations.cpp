#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
// ios::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);

int main()
{
int n;cin>>n;
int a[n+1];
int rest[n+1];rest[0]=0;
int imp[n+1];imp[0]=4; //1 for rest, 2 for gym, 3 for contest, 4 is indeterminate
for (int i = 1; i < n+1; ++i)
	{
		cin>>a[i];
		rest[i]=-1;
		imp[i]=-1;
	}
for (int d = 1; d < n+1; ++d)
	{
	    if (a[d] == 0)
	    {
	    	rest[d] = rest[d-1]+1;
	    	imp[d] = 1;
	    }
	    else if (a[d] == 1)
	    {
            if (imp[d-1] == 3)
            {
            	rest[d] = rest[d-1]+1;
	    	    imp[d] = 1;
            }
            else
            {
            	rest[d]=rest[d-1];
            	imp[d]=3;
            }
	    }
	    else if (a[d] == 2)
	    {
            if (imp[d-1] == 2)
            {
            	rest[d] = rest[d-1]+1;
	    	    imp[d] =1;
            }
            else
            {
            	rest[d]=rest[d-1];
            	imp[d]=2;
            }
	    }
	    else
        {
            if (imp[d-1] == 3) //contest
            {
            	rest[d] = rest[d-1];
	    	    imp[d] = 2;
            }
            else if (imp[d-1]==2) //gym
            {
            	rest[d]=rest[d-1];
            	imp[d]=3;
            }
            else if (imp[d-1] == 1) //rest
            {
                rest[d]=rest[d-1];
                imp[d]=4;
            }
            else if (imp[d-1] == 4)
            {
            	rest[d]=rest[d-1];
                imp[d]=4;
            }
	    }
	}
// for (int i = 1; i < n+1; ++i)
// {
// 	cout<<imp[i];
// }
// cout<<endl;
// for (int i = 1; i < n+1; ++i)
// {
// 	cout<<rest[i];
// }
cout<<rest[n];
}