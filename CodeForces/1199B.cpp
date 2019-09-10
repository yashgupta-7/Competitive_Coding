#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double H,L;
	cin>>H>>L;
	cout<<setprecision(30)<<(L*L-H*H)/(2*H);
}