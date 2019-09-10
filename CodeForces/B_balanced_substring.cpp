#include<bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f
// ios::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);

int includeLast(string str,int len)
{
   int n = len-1;
   int diff = 0; //1-0
   int maxLength = 0;
   len -= 1;
   while (len>=0)
   {
     if (str[len] == '0')
   	 diff --; else diff ++;
     if (diff == 0) maxLength = n-len+1;
   	 len--; 
   }
   return maxLength;
}

int main()
{
  int n;cin>>n;
  string str;
  //cin>>str;
  cin>>str;//cout<<str<<endl;
  int len = str.size();
  int arr[len];
  //memset(arr,sizeof(arr),-1);
  arr[0]=0;
  for (int i = 1; i < len; ++i)
  {
  	arr[i] = max(arr[i-1],includeLast(str,i+1));

  }
  cout<<arr[len-1];
 }
