#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<map>
#include<utility>
#include<queue>
#define ll long long
const int N=1e6+5;
using namespace std;
vector<int> adj[N];
map <int,int> join[N];
vector< int > bi[65];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> v;
	bool fl=0;
	for(int i=1;i<=n;i++){
		ll a;
		cin>>a;
		if(a!=0)
			v.push_back(i);
		if(fl)
			continue;
		int j=0;
		while(a){
			if(a%2==1){
				bi[j].push_back(i);
				if(bi[j].size()>2){
					fl=1;
					break;
				}
				else if(bi[j].size()==2&&join[bi[j][0]][bi[j][1]]==0){
					adj[bi[j][0]].push_back(bi[j][1]);
					adj[bi[j][1]].push_back(bi[j][0]);
					join[bi[j][0]][bi[j][1]]=1;
					join[bi[j][1]][bi[j][0]]=1;
				}
			}
			a/=2;
			j++;
		}


	}
	cout<<fl<<endl;
	if(fl)
		cout<<3<<endl;
	else{
		// n=200
		int ans=1e9;
		for(int i=1;i<=n;i++){
			if(v[i]==0)
				continue;
			bool vis[500];
			bool fl2=0;
			int dis[500];
			for(int j=0;j<v.size();j++){
				vis[v[j]]=0;
				dis[v[j]]=1e9;
			}
			queue< pair<int,int> > q;
			q.push(make_pair(i,0));
			dis[i]=0;
			while(!q.empty()){
				int node=q.front().first;
				int p=q.front().second;
				q.pop();
				for(int j=0;j<adj[node].size();j++){
					int u=adj[node][j];
					if(u==p)
						continue;
					if(u==i){
						ans=dis[node]+1;
						fl2=1;
						break;
					}
					if(vis[u])
						continue;
					q.push(make_pair(u,node));
					v[u]=1;
				}
				if(fl2)
				break; 
			}

		}
		if(ans==1e9)
			cout<<"-1"<<endl;
		else
		cout<<ans<<endl;
	}
	
}
