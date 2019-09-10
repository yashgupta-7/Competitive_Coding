#include <iostream>
 
int main(){
  int a,b,c;std::cin>>a>>b>>c;
  for(int x=0;x<=a&&x<=b;++x)
    if(a-x+b-x==c)return std::cout<<x<<' '<<b-x<<' '<<a-x<<'\n',0;
  std::cout<<"Impossible\n";
}