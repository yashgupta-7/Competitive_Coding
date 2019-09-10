#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)

vector<int> z_function(string s) {
	int n = (int) s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
	while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				++z[i];
	if (i + z[i] - 1 > r)
	l = i, r = i + z[i] - 1;
	}
	return z;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;cin>>N>>M;
	rep(i,0,N-1){
		cin>>sb[i];
	}

	string rbt;
	rep(i,0,N-1){
		rbt+="0";
	}
	
	rep(i,0,M-1){
        int x;
        cin>>x;
        rbt[x]=1;
	}

}