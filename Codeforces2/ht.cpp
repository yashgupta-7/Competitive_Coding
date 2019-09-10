#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
const int N = 1e5+7;
int p[N],r[N];

void unio(int s,int t){
	int rs = r[s];
	int rt = r[t];
	p[rs]=rt;
	r[s]=rt;
}

int find(int t){
	if(p[t]==t){
		return t;
	}
	return p[t] = find(p[t]) 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	int q;cin>>q;
	rep(i,1,n){
		p[i]=i;
		t[i]=i;
	}
	rep(i,1,q){
		int sj,tj;
		cin>>sj>>tj;
		unio(t[sj],t[tj]);
	}
	rep(i,1,n){
		cout<<find(i)<<" ";
	}
}