#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;cin>>n; //1,5,10,20,100
	int m = n/100;
	n = n%100;
	int memo[n+1];
	memo[0] = 0;
	memo[1] = 1;
	for (long long int i = 0; i < n+1; ++i)
	{
		if (i >= 100)
		{
            long long int v[] = {
            	       memo[i-100]+1,
            	       memo[i-20]+1,
            	       memo[i-10]+1,
            	       memo[i-5]+1,
            	       memo[i-1]+1
            	      };
            memo[i]=*min_element(v, v + 5);
		}
	    else if (i >= 20)
	    {
            long long int v[] = {
            	       // memo[i-100]+1,
            	       memo[i-20]+1,
            	       memo[i-10]+1,
            	       memo[i-5]+1,
            	       memo[i-1]+1
            	      };
            memo[i]=*min_element(v, v + 4);
		}
	    else if (i >= 10)
	    {
            long long int v[] = {
            	       // memo[i-100]+1,
            	       // memo[i-20]+1,
            	       memo[i-10]+1,
            	       memo[i-5]+1,
            	       memo[i-1]+1
            	      };
            memo[i]=*min_element(v, v + 3);
		}
	    else if (i >= 5)
	    {
            long long int v[] = {
            	       // memo[i-100]+1,
            	       // memo[i-20]+1,
            	       // memo[i-10]+1,
            	       memo[i-5]+1,
            	       memo[i-1]+1
            	      };
            memo[i]=*min_element(v, v + 2);
		}
	    else if (i >= 1)
	    {
            long long int v[] = {
            	       // memo[i-100]+1,
            	       // memo[i-20]+1,
            	       // memo[i-10]+1,
            	       // memo[i-5]+1,
            	       memo[i-1]+1
            	      };
            memo[i]=*min_element(v, v + 1);
		}
	}

	cout<<m + memo[n];
}