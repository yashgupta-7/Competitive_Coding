#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
#define int long long
const int M = 1e9+7;
const int N = 1e5+7;
int f[N],x[N],inc[N]; 

main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	int q;cin>>q;
	int f1;cin>>f1;
	int f2;cin>>f2;
	int a;cin>>a;
	int b;cin>>b;
	rep(i,1,n){
		cin>>x[i];
	}
	f[1]=f1;
	f[2]=f2;
	rep(i,3,N){
		f[i]=(a*f[i-2])%M+(b*f[i-1])%M;
		f[i]=f[i]%M;
	}
	rep(j,1,q){
		int l,r;
		cin>>l>>r;
		int t = r-l+1;
		if (l < r){
		inc[l]+=f1;
		inc[l]=inc[l]%M;
		
		inc[l+1]=(inc[l+1]+M+f2-(b*f1)%M)%M;
		//inc[l+1]=inc[l+1]%M;
		
		inc[r+1]=(inc[r+1]+M-f[t+1])%M;
		//inc[r+1]=inc[r+1]%M;
		
		inc[r+2]=(inc[r+2]+M-(a*f[t])%M)%M;
		//inc[r+2]=inc[r+2]%M;
		}
		else{
			inc[l]+=f1;
			inc[l]=inc[l]%M;

			inc[r+1]=(inc[r+1]+M-(b*f[1])%M)%M;
			//inc[r+1]=inc[r+1]%M;
		
			inc[r+2]=(inc[r+2]+M-(a*f[1])%M)%M;
			inc[r+2]=inc[r+2]%M;

		}
		
		// rep(l,1,n) cout<<inc[l]<<" ";
		// cout<<endl;
	}
	rep(k,2,n){
		inc[k]+=(a*inc[k-2])%M+(b*inc[k-1])%M;
		inc[k]=inc[k]%M;
	}
	rep(i,1,n){
		x[i]+=inc[i];
		x[i]=x[i]%M;
		cout<<x[i]<<" ";
	}

}