#include<iostream>
#include<algorithm>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;int l=lower_bound(a,a+n,x)-a,r=upper_bound(a,a+n,x)-a-1;if(l<=r&&a[l]==x)cout<<l<<" "<<r<<"\n";else cout<<"-1 -1\n";}
