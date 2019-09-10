#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
const int N = 3e6;
#define int long long
vector<pair<int,int> > adj[N];
int e[N],m[N],w[N],pr[N]; 

void rt(int r,int p)
{
	for (auto c : adj[r]){
		if (c.first != p){
			rt(c.first,r);
			pr[c.first]=r;
		}
	}
}


int dfse(int r){
    if (!e[r]){
    int res=0;
	int mx1 = 0;
	int mx2 = 0;
    for(auto c : adj[r]){
    	if (c.first!=pr[r]){
           int x = dfse(c.first)+c.second;
           if (mx1 < x){
                  mx2 = mx1;                 
                  mx1 = x;
           }
           else if (mx2 < x){
           	      mx2 = x;
           }
    	}
    }
    res = mx1 + w[r];
    e[r] = res;
    m[r] = res + mx2;
    return res;
	}
	else return e[r];
}

int dfsm(int r){
	if (!m[r]){
	int res=0;
	int mx1 = 0;
	int mx2 = 0;
    for(auto c : adj[r]){
    	if (c.first!=pr[r]){
           int x = dfse(c.first)+c.second;
          // cout<<x<<" ";
           if (mx1 < x){
                  mx2 = mx1;
                  mx1 = x;                 
           }
           else if (mx2 < x){
           	      mx2 = x;
           }
    	}
    }
   // cout<<mx1<<" "<<mx2<<endl;
    res = mx1 + mx2 + w[r];
    m[r] = res;
    return res;}
    else return m[r];
}



main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	rep(i,1,n){
		cin>>w[i];
	}
	rep(i,1,n-1){
		int u,v,c;
		cin>>u>>v>>c;
		adj[u].push_back({v,-c});
		adj[v].push_back({u,-c});
	}
	rt(1,0);
    int mx = -INF;
    dfse(1);
    //dfsm(1);
    //rep(i,1,n) dfsm(i);
    rep(i,1,n){
    	// cout<<pr[i]<<" ";
    	// cout<<e[i]<<" "<<m[i]<<endl;
    	mx = max(m[i],mx);
    	mx = max(e[i],mx);
    }
    cout<<mx;
}