#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
const int N = 1e5+7;
int l[N],tr[3*N],v[N],h[N];
pair<int,int> x[N];
vector<int> x2;

void build(int nd,int st,int ed)
{
	if(st==ed){
		tr[nd]=l[st];
	}
	else{
		int mid=(st+ed)/2;
		build(2*nd,st,mid);
		build(2*nd+1,mid+1,ed);
		tr[nd] = max(tr[2*nd],tr[2*nd]);
	}
}

int mx(int nd,int st,int ed,int l,int r)
{
	cout<<nd<<" "<<st<<" "<<ed<<" "<<l<<" "<<r<<" "<<endl;
	if (l>ed || r<st || l>r){
		return -INF;
	}
	else if (l<=st && ed<=r){
		return tr[nd];
	}
	int mid=(st+ed)/2;
	int m1 = mx(2*nd,st,mid,l,r);
	int m2 = mx(2*nd+1,mid+1,ed,l,r);
	cout<<m1<<" "<<m2<<endl;
	return max(m1,m2);
}

void update(int nd,int st,int ed,int idx,int val)
{
	cout<<idx<<" "<<val<<endl;
	if (st==ed){
		tr[idx]=val;
		l[idx]=val;
	}
	else{
		int mid =(st+ed)/2;
		if (st<=idx && idx<=mid){
			update(2*nd,st,mid,idx,val);
		}
		else{
			update(2*nd+1,mid+1,ed,idx,val);
		}
		tr[nd] = max(tr[2*nd],tr[2*nd+1]);
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	rep(i,1,n){
        int xi,hi;
        cin>>xi>>hi;
        x[i]={xi,i};
        h[i]=hi;
	}
	sort(x+1,x+n+1);
	x2.push_back(-INF);
	rep(i,1,n){
		x2.push_back(x[i].first);
	}
	rep(d,1,n) l[d] = d;
	build(1,1,N);
	repr(d,n,1){
		int xd = x[d].first;
		int hd = h[x[d].second];
		int g = xd+hd-1;
		cout<<g<<endl;
		vector<int>::iterator k = upper_bound(x2.begin()+d,x2.begin()+n+1,g);
		int k1 = k-x2.begin()-1;
		cout<<k1<<endl;
        int ld = mx(1,1,N,d,k1);
        update(1,1,N,d,ld);
        cout<<l[d]<<endl;
	}
	rep(j,1,n) v[x[j].second]=l[j]-j+1;
	rep(i,1,n) cout<<v[i]<<" ";
}