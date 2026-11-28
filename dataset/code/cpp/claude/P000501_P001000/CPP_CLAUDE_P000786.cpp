#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){int n;cin>>n;vector<long long>a(n),pre(n+1,0),suf(n+1,0);for(auto&v:a)cin>>v;
for(int i=0;i<n;i++)pre[i+1]=pre[i]+a[i];for(int i=n-1;i>=0;i--)suf[i]=suf[i+1]+a[i];
for(int i=0;i<n;i++)cout<<abs(pre[i]-suf[i+1])<<" \n"[i==n-1];}
