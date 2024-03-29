#include <bits/stdc++.h>
using namespace std;
 
int n, root, sum, v1, v2, dp[1000001];
vector<int> g[1000001];
void dfs(int u) {
	for(int v: g[u]) dfs(v), dp[u] += dp[v];
	if(dp[u] == sum/3 && u != root) {
		if(!v1) v1 = u, dp[u] = 0;
		else if(!v2) v2 = u, dp[u] = 0;
	}
}
int main() {
	scanf("%d",&n);
	for(int i = 1,p; i <= n; i++) {
		scanf("%d%d",&p,&dp[i]);
		sum += dp[i];
		g[p].push_back(i);
		if(p == 0) root = i;
	}
	if(sum%3) printf("-1"), exit(0);
	dfs(root);
	if(v1 && v2) printf("%d %d", v1,v2);
	else printf("-1");
}
