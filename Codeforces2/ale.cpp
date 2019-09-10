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
	int n;cin>>n;
	int res[2*n+7];
	int t = 2*n;
	if (n%2==0) cout<<"NO";
	else{
		// int i=1,k=1;
		// rep(j,1,n){
  //           res[k%t]=i;
  //           res[(n+k)%t]=i+1;
  //           k=n+k+1;
  //           i=i+2;
		// }
		// // res[2*n]=2*n;
		// // res[n]=2*n-1;
		cout<<"YES"<<endl;
		// rep(i,0,2*n-1) cout<<res[i]<<" ";

		int t = 2*n,i=1;
		rep(j,0,n-1){
			int te = (i+3)%t;
			if (te==0) te = t;
			cout<<i<<" "<<te<<" ";
			i=te+1;
		}
	}
}