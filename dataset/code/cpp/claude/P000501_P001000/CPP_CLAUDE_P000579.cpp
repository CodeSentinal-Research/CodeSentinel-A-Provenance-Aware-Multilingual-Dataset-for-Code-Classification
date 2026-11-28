#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;reverse(a.begin(),a.end());for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i==n-1];}
