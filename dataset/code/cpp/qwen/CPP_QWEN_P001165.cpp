#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<long long>a(n);for(int i=0;i<n;i++)cin>>a[i];long long mx=a[0],mn=a[0],res=a[0];for(int i=1;i<n;i++){long long t1=mx*a[i],t2=mn*a[i];mx=max({a[i],t1,t2});mn=min({a[i],t1,t2});res=max(res,mx);}cout<<res<<endl;return 0;}
