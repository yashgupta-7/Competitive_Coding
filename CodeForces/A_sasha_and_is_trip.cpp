#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;cin>> n;
	int v;cin>> v;
	int money = 0;
	int curr = 0;
	if ( n-1 <= v)
	{
		money = n-1;
	}
	else
	{
	curr = v;
	money = v;
	for (int i = 2; i < n+1; ++i)
	{
		curr--;
		if (n-i <= curr)
			break;
        money += i*(v-curr);
        curr = v;
	}}
    cout<<money;

}