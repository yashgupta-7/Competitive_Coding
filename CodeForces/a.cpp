#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	rep(j,1,t){
		int s,i,e;
		cin>>s>>i>>e;
		cout<<max(0,min(e+1,(e+s-i+1)/2))<<endl;
	}
}