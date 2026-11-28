#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;sort(a.begin(),a.end());
cout<<max(0,min({a[n-1]-a[2],a[n-2]-a[1],a[n-3]-a[0]}))<<"\n";}
