#include<bits/stdc++.h>
using namespace std;

char alphabet[] = {'_', 'a', 'b', 'c', 'd', 'e', 'f',
                       'g', 'h', 'i', 'j', 'k', 'l',
                       'm', 'n', 'o', 'p', 'q', 'r',
                       's', 't', 'u', 'v', 'w', 'x',
                       'y', 'z'};

string diff(char a, char b)
{
   int an = a - 'a' + 1;
   int bn = b - 'a' + 1;
   int cn;
   if (abs(bn - an) >= 2)
   	cn = (an+bn)/2;
   else
   {
   	cn = (max(an,bn)+2)%26 + 1;
   }
   string result(1, alphabet[cn]);
   return result;
   //return alphabet[cn];
}

int main()
{
   string s;
   getline(cin, s);
   int n = s.length();
   string to_rep;
   for (int i = 0; i < n-1; ++i)
   {
   	if (s.at(i) == s.at(i+1))
   	{
        
        if (i+2 <= n-1)
        {
        	to_rep = diff(s.at(i),s.at(i+2));
        	s.replace(i+1, 1, to_rep);
        }
        else
        {
        	to_rep = diff(s.at(i),s.at(i));
        	s.replace(i+1, 1, to_rep);
        }
   	}
   	
   }

   cout<<s;
   // for (int i = 1; i < 27; ++i)
   // {
   // 	for (int j = 1; j < 27; ++j)
   // 	{
   // 		if (diff(alphabet[i],alphabet[j]) == alphabet[i])
   // 			cout<<i<<j;
   // 	}
   // }
}