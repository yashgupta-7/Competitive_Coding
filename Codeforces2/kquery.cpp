#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
const int N=3e4+7;
int n;
int s[8*N],b[N],p[N],a[N],w[N],ans[N],i[N],j[N],k[N];
pair<int, int> ap[N],qp[N];

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		s[id] = 1;
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	s[id] = s[2 * id] + s[2 * id + 1];
}

void update(int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		s[id] = 0;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid);
	else
		update(p, 2 * id + 1, mid, r);
	s[id] = s[2 * id] + s[2 * id + 1];
}


int sum(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return s[id];
	int mid = (l + r)/2;
	return sum(x, y, id * 2, l, mid) +
	       sum(x, y, id*2+1, mid, r) ;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>n;
    rep(i,0,n-1){cin>>a[i];b[i]=1;ap[i]={a[i],i};}
    sort(ap,ap+n);
    rep(i,0,n-1)p[i]=ap[i].second;
    int q;cin>>q;
    rep(t,0,q-1){cin>>i[t]>>j[t]>>k[t];qp[t]={k[t],t};}
    sort(qp,qp+q);
    rep(i,0,q-1)w[i]=qp[i].second;
	build();
	int po = 0;
	for(int y = 0;y < q;++ y){
    // rep(i,0,2*n)cout<<s[i]<<" ";
    // cout<<endl;
	int x = w[y];
	while(po < n && a[p[po]] <= k[x])
		update(p[po++]);
	ans[x] = sum(i[x]-1, j[x] ); // the interval [i[x], j[x] + 1)
	}
	// rep(i,0,2*n)cout<<s[i]<<" ";
 //    cout<<endl;
	rep(t,0,q-1)cout<<ans[t]<<endl;
}