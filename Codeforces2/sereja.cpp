#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
const int N=8e6;
string b;
tuple<int,int,int> tr[N];

void build(int nd,int st,int en)
{
	if (st==en){
		if (b[st]=='(')
			tr[nd]={0,1,0};
		else if (b[st]==')')
			tr[nd]={0,0,1};
	}
	else{
		int mid=(st+en)/2;
		build(2*nd+1,st,mid);
		build(2*nd+2,mid+1,en);
		tuple<int,int,int> tp1=tr[2*nd+1];
		tuple<int,int,int> tp2=tr[2*nd+2];
		int t1 = get<0>(tp1)+get<0>(tp2)+2*min(get<1>(tp1),get<2>(tp2));
		int t2 = get<1>(tp1)+get<1>(tp2)-min(get<1>(tp1),get<2>(tp2));
		int t3 = get<2>(tp1)+get<2>(tp2)-min(get<1>(tp1),get<2>(tp2));
		tr[nd]={t1,t2,t3};
	}
}

tuple<int,int,int> query(int nd,int st,int en,int l,int r)
{
	//cout<<nd<<" "<<st<<" "<<en<<" "<<l<<" "<<r<<endl;
	if (l>r || l>en || r<st)
		return {0,0,0};
	else if (st==l && en==r)
		return tr[nd];
	else{
		int md=(st+en)/2;
		tuple<int,int,int> tp1=query(2*nd+1,st,md,l,min(md,r));
		tuple<int,int,int> tp2=query(2*nd+2,md+1,en,max(md+1,l),r);
		int t1 = get<0>(tp1)+get<0>(tp2)+2*min(get<1>(tp1),get<2>(tp2));
		int t2 = get<1>(tp1)+get<1>(tp2)-min(get<1>(tp1),get<2>(tp2));
		int t3 = get<2>(tp1)+get<2>(tp2)-min(get<1>(tp1),get<2>(tp2));
		return {t1,t2,t3};
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	cin>>b;
	int n=b.length();
	build(0,0,n-1);
	// rep(i,0,2*n) cout<<get<0>(tr[i])<<" ";
	// cout<<endl;
	int q;cin>>q;
	rep(i,0,q-1){
		int li,ri;
		cin>>li>>ri;
		cout<<get<0>(query(0,0,n-1,li-1,ri-1))<<endl;
	}
}
