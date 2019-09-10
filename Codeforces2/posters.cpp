#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
const int N = 10;
const int M = 40000;
int lazy[3*N],s[3*N],o[M];

void shift(int id,int st,int ed,int add)
{  
   lazy[2*id]+=lazy[id];
   lazy[2*id+1]+=lazy[id];
   lazy[id]=0;
}

void update(int id,int st,int ed,int l,int r,int add)
{
	if (r<st or l>ed)
		return ;
	else if (r>=ed && l<=st){
		 lazy[id]+=add;
   		 s[id] += (ed-st+1)*lazy[id];
   		 shift(id,st,ed,add);
		 return;}
	else {
		s[id] += (ed-st+1)*lazy[id];
		shift(id,st,ed,0);
		int mid = (st+ed)/2;
		update(2*id,st,mid,l,r,add);
		update(2*id+1,mid+1,ed,l,r,add);
		s[id]=s[2*id]+s[2*id+1];
		return;
	}
}

void cnt(int id,int st,int ed)
{
	if (st==ed){
		s[id]+=lazy[id];
		lazy[id]=0;
		return;
	}
	else{
		shift(id,st,ed,0);
		int mid = (st+ed)/2;
		cnt(2*id,st,mid);
		cnt(2*id+1,mid+1,ed);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	rep(i,1,t){
		int n;cin>>n;
		rep(j,1,n){
			int li,ri;
			cin>>li>>ri;
			update(1,1,N,li,ri,1);
			rep(x,1,20) cout<<s[x]<<" ";
			cout<<endl;
			rep(x,1,20) cout<<lazy[x]<<" ";
			cout<<endl;
		}
		cnt(1,1,N);
		rep(x,1,20) cout<<s[x]<<" ";
			cout<<endl;
		rep(x,1,20) cout<<lazy[x]<<" ";
			cout<<endl;
		rep(k,1,N) o[s[k]]++;
		int res=0;
		rep(l,1,M) if (o[l]) res++; 
		cout<<res;
	}
}