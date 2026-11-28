#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;int l,r;cin>>l>>r;
reverse(a.begin()+l-1,a.begin()+r);for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i==n-1];}
