#include<iostream>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;int a[n],x;for(auto&v:a)cin>>v;cin>>x;cout<<(find(a,a+n,x)!=a+n?"Found":"Not Found")<<"\n";}
