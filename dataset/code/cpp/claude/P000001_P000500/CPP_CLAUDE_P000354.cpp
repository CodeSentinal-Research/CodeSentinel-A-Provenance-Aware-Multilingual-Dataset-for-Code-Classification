#include<iostream>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;int a[n],x;for(auto&v:a)cin>>v;cin>>x;cout<<count(a,a+n,x)<<"\n";}
