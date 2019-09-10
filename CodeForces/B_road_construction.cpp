#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;cin>>n>>m;
    bool ap[n+1];// 1 to n
    for (int i = 0; i < n+1; ++i)
    {
    	ap[i] = false;
    }
    int a_i,b_i;
    for (int i = 0; i < m; ++i)
    {
    	cin>>a_i>>b_i;
    	ap[a_i] = true;
    	ap[b_i] = true;
    }
    int nf;
    for (int i = 1; i < n+1; ++i)
    {
    	if (ap[i]==false)
           {nf=i;break;}
    }
    cout<<n-1<<endl;
    for (int i = 1; i < n+1; ++i)
    {
    	if (i != nf)
    	{
    		cout<<nf<<" "<<i<<endl;
    	}
    }
    // bool rp[n+1][n+1];
    // for (int i = 0; i < n+1; ++i)
    // {
    // 	for (int j = 0; j < n+1; ++j)
    // 	{
    // 		rp[i][j] = true;
    // 	}
    // }
    // int a_i,b_i;
    // for (int i = 0; i < m; ++i)
    // {
    // 	cin>>a_i>>b_i;
    // 	rp[a_i][b_i] = false;
    // 	rp[b_i][a_i] = false;
    // }

}