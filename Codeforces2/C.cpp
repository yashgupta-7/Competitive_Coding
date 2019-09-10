#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 100000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define int long long

main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	int adj[n+1][n+1];
	int distance[n+1][n+1];
	rep(i,1,n){
		string s;cin>>s;
		rep(j,1,n){
             adj[i][j]=s[j-1]-'0';
		}
	}
 //    rep(i,1,n){3


	// 	rep(j,1,n){
 //             cout<<adj[i][j]<<endl;
	// 	}
	// }
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) distance[i][j] = 0;
			else if (adj[i][j]) distance[i][j] = adj[i][j];
			else distance[i][j] = INF;
		}
	}

	// rep(i,1,n){
	// 	rep(j,1,n){
 //             cout<<distance[i][j]<<endl;
	// 	}
	// }

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				distance[i][j] = min(distance[i][j],
							distance[i][k]+distance[k][j]);
			}
		}
	}

	// rep(i,1,n){
	// 	rep(j,1,n){
 //             cout<<distance[i][j]<<endl;
	// 	}
	// }
	

	int m;cin>>m;
	int p[m+1];
	rep(k,1,m){
		cin>>p[k];
	}
	int st = p[1];
	int curr = p[1];
	int l = 1;
	vector<int> res;
	res.push_back(st);
	rep(k,2,m){
		if (distance[curr][p[k]] == l)
			{l++;continue;}
		else{
			curr=p[k-1];
			res.push_back(p[k-1]);
			l=1;
			k--;
		}
	}
	res.push_back(p[m]);
	cout<<res.size()<<endl;
	for(auto d : res){
		cout<<d<<" ";
	}
}