#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i,a,b) for (int i = a; i >= b; i--)

void bfs(int sx,int sy){
		if (mz[sx][sy+1]=='.'){
			q.push({})
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,1,n){
		rep(j,1,m){
			cin>>mz[i][j];
			if (mz[i][j]=='X'){
				int posx=i;
				int posy=j;
			}			
		}
	}


}