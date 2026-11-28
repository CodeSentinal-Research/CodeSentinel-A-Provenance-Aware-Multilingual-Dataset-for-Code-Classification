#include<bits/stdc++.h>
using namespace std;
long long rob(vector<int>&a,int l,int r){long long p=0,c=0;for(int i=l;i<=r;i++){long long t=c;c=max(p+a[i],c);p=t;}return c;}
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];if(n==1){cout<<a[0]<<endl;return 0;}cout<<max(rob(a,0,n-2),rob(a,1,n-1))<<endl;return 0;}
