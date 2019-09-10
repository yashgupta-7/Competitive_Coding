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
	int k;cin>>k;
	if (k%2==0){
		cout<<"NO";
		return 0;
	}
	if (k==1){
		cout<<"YES"<<endl<<"2 1"<<endl<<"1 2";
		return 0;
	}
	cout<<"YES"<<endl;
	cout<<2*(k+2)<<" "<<(k+2)*k<<endl;
	int j = k/2;
	rep(p,1,k){
		rep(q,p+1,k+1){
			if (p%2!=1 || q!=p+1 || j==0)
				cout<<p<<" "<<q<<endl;
			else {
				cout<<p<<" "<<k+2<<endl;
				cout<<q<<" "<<k+2<<endl;
				j--;
			}
		}
	}
	j = k/2;
	rep(p,1,k){
		rep(q,p+1,k+1){
			if (p%2!=1 || q!=p+1)
				cout<<p+k+2<<" "<<q+k+2<<endl;
			else if (j==0)
				cout<<p+k+2<<" "<<q+k+2<<endl;
			else {
				cout<<p+k+2<<" "<<k+2+k+2<<endl;
				cout<<q+k+2<<" "<<k+2+k+2<<endl;
				j--;
			}
		}
	}
	cout<<k+2<<" "<<k+2+k+2;
}