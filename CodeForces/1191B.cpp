#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
vector<int> a;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,h;cin>>n>>h;
    for (int i = 0; i < n; ++i)
    {
    	int ai;
    	cin>>ai;
    	a.push_back(ai);
    	//cout<<ai<<endl;
    }
    int mx=0;
    for (int i = 1; i < n+1; ++i)
    {
        vector<int> b;
        b = a;
        sort(b.begin(),b.begin()+i);
        int th=0;
        for(int j=i-1;j>=0;j=j-2)
        {
        	th+=b[j];
        	//cout<<b[j]<<endl;
        }
        
        //cout<<th<<endl;
        if (th <= h)
        {
        	mx=i;
        }
        else
        {
        	break;
        }
    }
    cout<<mx;
}