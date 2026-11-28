#include<iostream>
#include<algorithm>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;cout<<upper_bound(a,a+n,x)-lower_bound(a,a+n,x)<<"\n";}
