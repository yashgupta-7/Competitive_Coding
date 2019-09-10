#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str ;
	getline(cin, str);
	
    int n_q = 0;
    int n_a = 0;
    int n_qa = 0;
    int n_qaq = 0;
    while (str != "")
    {
    	if (str.at(0) == 'Q')
    	{
            n_q++;
            n_qaq += n_qa;
            str = str.substr(1);
    	}
    	else if(str.at(0) == 'A')
    	{
             n_a++;
             n_qa += n_q;
             str = str.substr(1);
    	}
    	else
    	{
    		str = str.substr(1);
    	}
    }

    cout<<n_qaq;
}