#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int m,n,k;cin>>m>>n>>k;vector<int>c(m+n);for(auto&v:c)cin>>v;sort(c.begin(),c.end());cout<<c[k-1]<<"\n";}
