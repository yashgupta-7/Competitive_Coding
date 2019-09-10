#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
const int N = 2e6;
int lo[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	rep(i,1,t){
		string s;cin>>s;
		int l = s.size();

		int po=l-1;
		repr(k,l-1,0){
			if(s[k]=='1'){
				rep(j,k+1,po){
					lo[j]=k;
				}
				po=k;
			}
			if(k==0 && s[k]!='1'){
				rep(j,0,po){
					lo[j]=-1;
				}
			}
		}
		lo[0]=-1;
 
		//rep(i,0,l-1)cout<<lo[i]<<" ";
		//cout<<endl;
		int res=0;
		repr(q,l-1,0){
			int p = q;
			if(s[p]=='1'){
				int m = 1;
				res++;
				while(lo[p]!=-1 && m<=l){
				if (q-lo[p]>30) break;
				m+=pow(2,(q-lo[p]));
				if(q-lo[lo[p]]>=m) res++;
				p=lo[p];}
			}
			else{
				int m = 0;
				while(lo[p]!=-1 && m<=l){
				if (q-lo[p]>30) break;
				m+=pow(2,(q-lo[p]));
				if(q-lo[lo[p]]>=m) res++;
				p=lo[p];}
			}
			//cout<<q<<" "<<res<<endl;
		}
		cout<<res<<endl;
	}
}