#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int m,n;cin>>m>>n;vector<int>a(m),b(n);for(auto&v:a)cin>>v;for(auto&v:b)cin>>v;vector<int>c;c.insert(c.end(),a.begin(),a.end());c.insert(c.end(),b.begin(),b.end());sort(c.begin(),c.end());int t=m+n;if(t%2)cout<<c[t/2]<<"\n";else cout<<(c[t/2-1]+c[t/2])/2.0<<"\n";}
