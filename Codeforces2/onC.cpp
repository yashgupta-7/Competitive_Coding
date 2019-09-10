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
	int T;cin>>T;
	rep(t,0,T-1){
		int d;cin>>d;
		int q = d/9;
		int r = d%9;
		cout<<r+1<<endl;
	}
}