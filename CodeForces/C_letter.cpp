#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;cin>>str;
    int len = str.size();
    int upper = 0;
    int up[len];
    for (int i = 0; i < len; ++i)
    {
    	int n = str[i]-'A';
    	if (n>=0 && n<26)
    	{
    		upper++;
    	}
    	up[i]=upper;
    }
    int cng = INF;
    for (int i = 0; i < len; ++i)
     {
     	cng = min(cng, 1+ i - up[i] + up[len-1] - up[i]);
     } 
     cout<<min(cng,up[len-1]);
}
