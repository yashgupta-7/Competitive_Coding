#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
const int N = 1e5+7;
int pnm1[N],snm1[N],pnm2[N],snm2[N],pc[N],sc[N],dp[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	string p;cin>>p;
	int k = p.length();
	int c = 2;
	string fnm1 = "1";
	int lnm1 = 1;
	string fnm2 = "0";
	int lnm2 = 1;
	string cs;
	if (p[0]==fnm1[0]){
		pnm1[1] = 1;
	}
	if (p[k-1]==fnm1[lnm1-1]){
		snm1[1] = 1;
	}
	if (p[0] == fnm2[0]){
		pnm2[1] = 1;
	}
	if (p[k-1]==fnm2[lnm2-1]){
		snm2[1] = 1;
	}


	while(c<=n){
		cs = fnm1+fnm2;
		rep(i,1,lnm1){
			pc[i] = pnm1[i];
		}
		if (pc[lnm1]==1){
			int it1 = 0;
			int it2 = lnm1;
			while(it1<lnm2 && it2<k && fnm2[it1]==p[it2]){
				pc[it2+1] = 1;
				it1++;
				it2++;
			}
		}
		rep(i,1,lnm2){
			sc[i] = snm2[i];
		}
		if (sc[lnm2]==1){
			int x = lnm2+1;
			int it1 = lnm1-1;
			int it2 = k-lnm2-1;
			while(it1>-1 && it2>-1 && fnm1[it1]==p[it2]){
				sc[x] = 1;
				x++;
				it1--;
				it2--;
			}
		}
		cout<<fnm2<<" "<<fnm1<<endl;
		rep(i,1,10){
			cout<<pnm2[i]<<" "<<snm2[i]<<" "<<pnm1[i]<<" "<<snm1[i]<<" "<<pc[i]<<" "<<sc[i]<<endl;
		}

		dp[c] = dp[c-1]+dp[c-2];
		rep(l,1,k-1){
		if (snm1[l] && pnm2[k-l]){
			dp[c]++;
			}
		}
		cout<<dp[c]<<endl;

		lnm2 = lnm1;
		lnm1 = cs.length();
		rep(j,0,N){
		pnm2[j] = pnm1[j];
		snm2[j] = snm1[j];
		pnm1[j] = pc[j];
		snm1[j] = sc[j];}
		fnm2 = fnm1;
		fnm1 = cs;
		c++;
		rep(i,0,N) {
			pc[i]=0;
			sc[i]=0;
		}
	}
}