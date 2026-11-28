#include<iostream>
#include<algorithm>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;cout<<count(a,a+n,x)<<"\n";}
