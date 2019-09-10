#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)
const int N = 5007;
int tim[N][N],dp[N][N];
bool dne[N][N];
vector<int> adj[N],adjr[N];

int dpf(int i,int j)
{
	if (!dne[i][j]){
        for(auto x : adjr[i]){
			dp[i][j] = min(dpf(x,j-1)+tim[x][i],dp[i][j]);
		}
		dne[i][j] = true;
		return dp[i][j];   
	}
	else{
        return dp[i][j];
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,t;
	cin>>n>>m>>t;
	rep(i,1,m){
		int ui,vi,ti;
		cin>>ui>>vi>>ti;
		tim[ui][vi] = ti;
		adj[ui].push_back(vi);
		adjr[vi].push_back(ui);
	}

	rep(i,1,n){
		rep(j,1,m+1){
			dp[i][j] = INF;
			dne[i][j] = false;
		}
	}
	dp[1][1]=0;
	int res;
	rep(i,1,m+1){
		if (dpf(n,i) <= t)
			res = i;
	}
	// rep(i,1,n){
	// 	rep(j,1,m){
	// 		cout<<dpf(i,j)<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<res<<endl;
	vector<int> path;
	int curr = n;
	while(res >= 1){
		for(auto pre : adjr[curr]){
			if ((dp[pre][res-1]+tim[pre][curr]) == dp[curr][res]){
				path.push_back(pre);
				curr = pre;
				break;
			}
		}
		if (curr == 1)
			break;
		res--;
	}
	repr(i,path.size()-1,0){
		cout<<path[i]<<" ";
	}
	cout<<n;
}