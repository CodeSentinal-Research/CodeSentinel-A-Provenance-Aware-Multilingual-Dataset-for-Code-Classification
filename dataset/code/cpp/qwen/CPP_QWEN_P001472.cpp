#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];sort(a.begin(),a.end());set<vector<int>>res;for(int i=0;i<n-2;i++){int l=i+1,r=n-1;while(l<r){int s=a[i]+a[l]+a[r];if(s==0){res.insert({a[i],a[l],a[r]});l++;r--;}else if(s<0)l++;else r--;}}for(auto&v:res){for(int x:v)cout<<x<<" ";cout<<"\n";}return 0;}
