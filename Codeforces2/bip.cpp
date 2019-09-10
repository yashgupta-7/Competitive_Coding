#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
const int N = 107;
int ld[N],rd[N],lv[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;cin>>T;
	rep(i,1,T){
		bool p =true;
		int n,m,d,D;
		cin>>n>>m>>d>>D;
		if (m<n*d){
			cout<<-1<<endl;
			p=0;
			}
		else{
			rep(l,0,n-1){
				ld[l]=d;
				lv[l]=(d+l-1)%n;
			}
			rep(r,0,n-1){
				rd[r]=d;
			}
			m=m-n*d;
			int cn=0;
			while(m>0){
				ld[cn]++;
				rd[(lv[cn]+1)%n]++;
				lv[cn]=(lv[cn]+1)%n;
				cn=(cn+1)%n;
				m--;
			}
			rep(k,0,n-1){
				//cout<<rd[k]<<" ";
				if (ld[k] > D)
					{cout<<-1<<endl;
						
					 p = 0;
					break;}
			}
			cout<<endl;
			if (p) {
				rep(k,0,n-1){
				rep(g,0,ld[k]-1){
					cout<<k+1<<" "<<(g+k)%n+1<<endl;
				}
			}
		}

		}
	}
}