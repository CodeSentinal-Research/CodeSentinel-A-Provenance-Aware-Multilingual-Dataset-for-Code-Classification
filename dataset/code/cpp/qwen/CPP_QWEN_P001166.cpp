#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<long long>a(n);long long sum=0,mx=-1e18,mn=1e18;for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];mx=max(mx,a[i]);mn=min(mn,a[i]);}long long cur=0,cmax=-1e18;for(int i=0;i<n;i++){cur+=a[i];cmax=max(cmax,cur);if(cur<0)cur=0;}long long cmin=0,cminres=1e18;for(int i=0;i<n;i++){cmin+=a[i];cminres=min(cminres,cmin);if(cmin>0)cmin=0;}cout<<max(cmax,sum-cminres)<<endl;return 0;}
