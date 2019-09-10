#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
typedef vector<int>::iterator itr;
vector<int> p,q,r;

inline void bf(int ps,int qs,int rs,int n)
{	
	// cout<<ps<<" "<<n<<endl;

	int t=rs-ps-qs;
	rep(i,ps,ps+n-1){
		rep(j,qs,qs+n-1){
			r[t+i+j]+=p[i]*q[j];
		}
	}
	return;
}

void multiply(int ps,int qs,int rs,int n)
{
	// cout<<n<<endl;
	rep(i,rs,rs+2*n-1) {r[rs]=0;}
	if (n <= 16){
		bf(ps,qs,rs,n);
		return;
	}
	else{
	int k = n/2;
    multiply(ps,qs,rs,k);
    // cout<<"hey1"<<endl;
    multiply(ps+k,qs+k,rs+n,k);
    // cout<<"hey2"<<endl;
    vector<int> t;
    t.resize(2*n);
    rep(j,rs,rs+2*n-1) {t[j-rs]=r[j];r[j]=0;}

    // rep(f,0,2*n-1) cout<<t[f]<<" ";
    // cout<<endl;

    rep(i,ps,ps+k-1) p[i]+=p[i+k];

    // rep(f,ps,ps+n-1) cout<<p[f]<<" ";
    // cout<<endl;

    rep(i,qs,qs+k-1) q[i]+=q[i+k];
    multiply(ps,qs,rs+k,k);
    // cout<<"hey3"<<endl;
    rep(j,rs,rs+2*n-1) r[j]+=t[j-rs];
    rep(j,rs+k,rs+k+n-1) { r[j]=r[j]-t[j-rs-k]-t[j-rs+k];}
    rep(i,ps,ps+k-1) p[i]-=p[i+k];
    rep(i,qs,qs+k-1) q[i]-=q[i+k];
    // cout<<"hey4"<<endl;
    // rep(f,ps,ps+n-1) cout<<p[f]<<" ";
    // cout<<endl;
    }
    
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	n=(1<<18);
	int x;
    rep(i,0,n-1){
       cin>>x;
       p.push_back(x);
    }
    rep(i,0,n-1){
    	cin>>x;
    	q.push_back(x);
    }
    r.resize(2*n);
    //bf(0,0,0,n);
    // cout<<r.size()<<endl;
    multiply(0,0,0,n);
    // cout<<"hey"<<endl;
    // cout<<r.size()<<endl;
    // cout<<r[r.size()-2]<<endl;
    rep(i,0,2*n-2){
    	cout<<r[i]<<" ";
    }
}