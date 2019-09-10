#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int mxa=-INF,mxb=-INF;
	int n;cin>>n;
	int a[n],b[n];
	rep(i,0,n-1){
		cin>>a[i];
		mxa=max(mxa,a[i]);
	}
	int m;cin>>m;
	rep(i,0,m-1){
		cin>>b[i];
		mxb=max(mxb,b[i]);
	}
	cout<<mxa<<" "<<mxb;
}