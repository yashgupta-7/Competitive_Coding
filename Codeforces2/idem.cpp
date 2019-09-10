#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
#define int long long
const int N = 207;
int gvis[N],vis[N],f[N];

 main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	rep(i,1,n){
		cin>>f[i];
	}
	int lm = 1;
	int mtr = -INF;
	rep(i,1,n){
		if (!gvis[i]){

			//cout<<i<<endl;

			rep(j,1,n) vis[j]=0;
			int cnt = 1;
			vis[i]=1;
			gvis[i]=1;
			int next = f[i];
			while(!vis[next]){
				cnt++;
				vis[next] = cnt;
				gvis[next] = 1;
				next = f[next];
				//cout<<cnt<<" ";
			}
			int cl = cnt+1-vis[next];

			//cout<<cl<<endl;

			int tr = vis[next]-1;

			//cout<<tr<<endl;

            lm = lm*cl/__gcd(lm,cl);
            mtr = max(mtr,tr);
		}
	}
	rep(i,1,INF){
		if (lm*i >= mtr){
			lm = lm*i;
			break;
		}
	}
	cout<<lm;
}