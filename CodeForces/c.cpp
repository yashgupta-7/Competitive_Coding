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
	rep(i,1,t){
		string s;cin>>s;
		int l = s.size();
		s = "s"+s;
		int ip = 0;
		rep(j,1,l){
			if (s[j]=='1'){
				no[ip] = j;
				ip = j;
			}			
		}
		int res=0;
		rep(k,1,l){

		}
	}
}