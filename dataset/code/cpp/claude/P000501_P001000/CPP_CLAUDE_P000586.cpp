#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;int k;cin>>k;
for(int i=0;i+k<=(int)a.size();i+=k)reverse(a.begin()+i,a.begin()+i+k);
for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i==n-1];}
