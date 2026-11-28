#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n*n);for(auto&x:a)cin>>x;sort(a.begin(),a.end());for(int i=0;i<n*n;i++)cout<<a[i]<<" \n"[i==n*n-1];}
