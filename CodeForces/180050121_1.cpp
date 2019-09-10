#include<bits/stdc++.h>
using namespace std;

const int N = 1000051;
char ori[N];
int type[N];
bool isp[N];
int min_diff[N];
int diff[N];
	

int main()
{
	for (int i = 0; i < N; ++i)
	{
		isp[i] = false;
	}

	int n;cin>>n;
	
	
	for (int i = 1; i < N; ++i)
	{
		min_diff[i] = N;
	}

	for (int i = 0; i < N; ++i)
	{
		diff[i]=0;
	}
    
    char c;
	int t;
	for (int i = 1; i < n+1; ++i)
	{
		cin>>c>>t;
		ori[i]=c;
		type[i]=t;
		isp[t] = true;
		if (c == 's')
		{
             diff[t]++;
		}
		else if (c == 'e')
		{
			diff[t]--;
		}
		min_diff[t] = min(min_diff[t],diff[t]);
	}

	int mnnt = 0;
	int ind = 1;
	int nnt[n+1];
	int num = 0;
	for (int i = 1; i < N; ++i)
	{
		if (min_diff[i] == 0 && isp[i] && diff[i] == 0)
		{
			num++;
		}
		if(diff[i]==0)
		isp[i]=1;
		else
		isp[i]=0;
		
		diff[i] = 0;
	}
	nnt[1] = num;
	mnnt = num;
	for (int i = 2; i < n+1; ++i)
	{
		nnt[i] = nnt[i-1];
		if(!isp[type[i-1]])
		continue;
		int t = type[i-1];
		if (ori[i-1] == 's')
		{
           diff[t]++;
           if (diff[t] == min_diff[t] + 1)
           	nnt[i]--;
		}
		else if (ori[i-1] == 'e')
		{
           diff[t]--;
           if (diff[t] == min_diff[t])
           	nnt[i]++;
		}
		if (mnnt < nnt[i])
		{
			mnnt = nnt[i];
			ind = i;
		}
	}
	cout<<ind<<" "<<mnnt;
}