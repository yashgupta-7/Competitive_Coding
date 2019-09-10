#include<bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool invert) {
int n = a.size();
for (int i = 1, j = 0; i < n; i++) {
int bit = n >> 1;
for (; j & bit; bit >>= 1)
j^=bit;
j^=bit;
if (i < j)
swap(a[i], a[j]);
}
for (int len = 2; len <= n; len <<= 1) {
double ang = 2 * PI / len * (invert ? -1 :
1);
cd wlen(cos(ang), sin(ang));
for (int i = 0; i < n; i += len) {
cd w(1);
for (int j = 0; j < len / 2; j++) {
cd u = a[i+j], v = a[i+j+len/2] *
w;
a[i+j] = u + v;
a[i+j+len/2] = u - v;
w *= wlen;
}
}
}
if (invert) {
for (cd & x : a)
x /= n;
}
}
// a and b can be of arbitrary lengths not
// can easily tweak the code to multiply complex
// numbers too
vector<int> multiply(vector<int> const& a, vector<
int> const& b) {
vector<cd> fa(a.begin(), a.end()), fb(b.begin
(), b.end());
int n = 1;
while (n < a.size() + b.size())
n <<= 1;
fa.resize(n);
fb.resize(n);
fft(fa, false);
fft(fb, false);
for (int i = 0; i < n; i++)
fa[i] *= fb[i];
fft(fa, true);
vector<int> result(n);
for (int i = 0; i < n; i++)
result[i] = round(fa[i].real());
return result;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<int> a,b;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	for(int i=n;i<2*n;i++)
		a.push_back(a[i-n]);
	b.resize(n);
	for(int i=0;i<n;i++)
		b[i]=0;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		// x--;
		b[x]=1;
	}
	reverse(b.begin(),b.end());
	vector<int> res=multiply(a,b);
	int sum=0;
	for(int i=n;i<2*n;i++)
		sum+=(res[i]==m);
	cout<<sum<<endl;


}
