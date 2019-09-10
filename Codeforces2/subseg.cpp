#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
const int N = 1e5+7;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;cin>>n>>k;
	rep(i,0,n-1){
		cin>>a[i];
	}
	set<int> q;
	int sz=0;
	rep(j,0,k-1) {
		if (q.find(a[j])!=q.end())
			{ q.erase(a[j]); sz--; }
		else
            { q.insert(a[j]); sz ++; }
    }
	cout<<*q.rbegin()<<endl;
	int e = k;
	rep(i,1,n-k){
        q.erase(a[e-k]);
        sz--;
        if (q.find(a[e])!=q.end())
			{ q.erase(a[e]); sz--; }
		else
            { q.insert(a[e]); sz++; }
        cout<<*q.rbegin()<<endl;
        e++;
	}
}