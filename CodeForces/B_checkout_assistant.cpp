#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long int

ll c[2005];
int t[2005];

int knapSack(int W, ll wt[], int val[], int n) 
{ 
   int i;
   ll w; 
   int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i] <= w) 
                 K[i][w] = max(val[i] + K[i-1][w-wt[i]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
    for (int i = 1; i < n+1; ++i)
    {
    	cin>>t[i];
    	cin>>c[i];
    	t[i]++;
    }
    ll cost = 0;
    while(knapSack(cost,c,t,n) < n)
    {
    	cost++;
    	//cout<<cost<<endl;
    }
    cout<<cost;
}