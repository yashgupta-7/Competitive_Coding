#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
# define INF 2000000000
vector<int> mx[10];


void printKMax(int arr[], int n, int k) 
{  
    std::deque<int> Qi(k); 
  
    /* Process first k (or first window) elements of array */
    int i; 
    for (i = 1; i < k+1; ++i) { 
        // For every element, the previous smaller elements are useless so 
        // remove them from Qi 
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); // Remove from rear 
  
        // Add new element at rear of queue 
        Qi.push_back(i); 
    } 
  
    // Process rest of the elements, i.e., from arr[k] to arr[n-1] 
    for (; i < n+1; ++i) { 
        // The element at the front of the queue is the largest element of 
        // previous window, so print it 
        mx[k].push_back(arr[Qi.front()]); 
  
        // Remove the elements which are out of this window 
        while ((!Qi.empty()) && Qi.front() <= i - 1 - k) 
            Qi.pop_front(); // Remove from front of queue 
  
        // Remove all elements smaller than the currently 
        // being added element (remove useless elements) 
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); 
  
        // Add current element at the rear of Qi 
        Qi.push_back(i); 
    } 
  
    // Print the maximum element of last window 
    mx[k].push_back(arr[Qi.front()]); 
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;cin>>n;
	int x,y;cin>>x>>y;
	int a[n+1];
	for (int i = 1; i < n+1; ++i)
	{
		cin>>a[i];
	}
	int m = -1;
	mx[x].push_back(-1);
	mx[y].push_back(-1);
	for (int j = 1; j < x+1; ++j)
	{
			m = max(m,a[j]);
			cout<<m<<" ";
			mx[x].push_back(m);
	}
	m = -1;
	printKMax(a,n,x);
	printKMax(a,n,y);
	for (int j = n+1-y; j < n+1; ++j)
	{
			m = max(m,a[j]);
			mx[y].push_back(m);
	}
	for (int i = 1; i < n+1; ++i)
	{
		cout<<mx[x][i]<<" "<<mx[y][i]<<" ";
	}

	for (int i = 1; i < n+1; ++i)
	{
		cout<<mx[x][i]<<" "<<mx[y][i]<<" ";
		if (i == 1 && mx[y][i+y] > a[i])
		{
			cout<<i;
			return 0;
		}
		else if (i == n && mx[x][i-1] > a[i])
		{
			cout<<i;
			return 0;
		}
		else if (mx[x][i-1] > a[i] && mx[y][i+y] > a[i])
		{
			cout<<i;
			return 0;
		}
	}

	
}