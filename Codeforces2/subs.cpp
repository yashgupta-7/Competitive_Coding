#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
const int N = 1e7;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	int k;cin>>k;
    rep(i,0,n-1) cin>>a[i];
    map<int,int> f;
    set<int> s;
    rep(j,0,k-1){
    	f[a[j]]++;
        if (f[a[j]] > 1){
        	s.erase(a[j]);
        }
        else {
        	s.insert(a[j]);
        }
    }
    if (s.empty()){
    	cout<<"Nothing"<<endl;
    }
    else{
    	cout<<*s.rbegin()<<endl;
    }
    rep(j,k,n-1){
    	f[a[j]]++;
    	f[a[j-k]]--;
    	if (f[a[j]] == 1){
        	s.insert(a[j]);
        }
        else {
        	s.erase(a[j]);
        }
        if (f[a[j-k]] == 1){
        	s.insert(a[j-k]);
        }
        else { 
        	s.erase(a[j-k]);
        }
        if (s.empty()){
    	cout<<"Nothing"<<endl;
    	}
    	else{
    	cout<<*s.rbegin()<<endl;
    	}
    }

}