#include<bits/stdc++.h>
using namespace std;
int main(){int n,t;cin>>n>>t;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];sort(a.begin(),a.end());set<vector<int>>res;for(int i=0;i<n-3;i++)for(int j=i+1;j<n-2;j++){int l=j+1,r=n-1;while(l<r){long long s=(long long)a[i]+a[j]+a[l]+a[r];if(s==t){res.insert({a[i],a[j],a[l],a[r]});l++;r--;}else if(s<t)l++;else r--;}}for(auto&v:res){for(int x:v)cout<<x<<" ";cout<<"\n";}return 0;}
