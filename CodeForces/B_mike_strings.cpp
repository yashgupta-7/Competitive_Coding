#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long;

void rotate(string &a)
{
	 a = a.substr(1) + a.substr(0,1);
	 //return a;
}

int cng (string a, string b, int n)
{
   //cout<<a<<" "<<b<<" ";
   if (a == b) 
   	{//cout<<0<<endl; 
   		return 0;}
   int mov = 0;
   for (int i = 0; i < n; ++i)
   {
   	rotate(a);
   	////cout<<a<<endl;
   	mov++;
   	if (a == b) 
   		{//cout<<mov<<endl;
   			return mov;}
   }
   //cout<<mov<<endl;
   return 100000;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
    string s[n+1];
    for (int i = 1; i < n+1; ++i)
    {
    	cin>>s[i];
    }
    int l = s[1].size();//cout<<l;

    int min_moves = INF;

    for (int i = 1; i < n+1; ++i)
    {
    	int ans = 0;
        for (int j = 1; j < n+1; ++j)
        {
        	//cout<<ans<<" ";
        	ans += cng(s[j],s[i],l);
        }
        //cout<<ans<<endl;
        min_moves = min(min_moves, ans);
    }
    if (min_moves >= 100000)
    	cout<<-1;
        else cout<<min_moves<<endl;
    //cout<<cng("zwoxz","xzzwo",5);
}