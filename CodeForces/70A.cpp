#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T;cin>>T;
    for (int i = 0; i < T; ++i)
    {
    	string x,y;cin>>x>>y;
    	int  pos=0;
    	int posy=0;
    	for(int i=y.size()-1;i>=0;i--)
    	{
    		if (y[i]=='1')
    			{pos=i;break;}
    		posy++;
    	}
    	int posx=x.size()-1-posy;
    	int k=0;
    	while(x[posx]!='1')
    	{
    		posx--;
    		k++;
    	}
    	cout<<k<<'\n';
    }
}