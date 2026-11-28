#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;
long long tot=0;
for(int i=0;i<n;i++){int mn=a[i],mx=a[i];for(int j=i;j<n;j++){mn=min(mn,a[j]);mx=max(mx,a[j]);tot+=mx-mn;}}
cout<<tot<<"\n";}
