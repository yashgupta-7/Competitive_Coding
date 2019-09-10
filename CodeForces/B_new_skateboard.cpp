#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[1000000];
	scanf("%s",s);
	long long int result = 0;
	long long int n = strlen(s) + 1;
	//cout<< n;
	while (n >= 3)
	{
		n--;
		long long int last = *(s+n-1) - '0';
		long long int sec_last = *(s+n-2) - '0';
		if (last%4 == 0) result++;
		//if(sec_last%4 == 0) result++;
		if ((10*sec_last + last)%4 == 0)
		{
			result += n - 1;
		}
		s[n-1] = '\0';
	}
    
    long long int first = *(s) - '0';
    if(first%4 == 0) result++;
	//printf("%s\n",s);
	printf("%lld\n", result);
}