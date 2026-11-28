#include<bits/stdc++.h>
using namespace std;
int main(){int n,t;cin>>n>>t;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];sort(a.begin(),a.end());int res=a[0]+a[1]+a[2];for(int i=0;i<n-2;i++){int l=i+1,r=n-1;while(l<r){int s=a[i]+a[l]+a[r];if(abs(s-t)<abs(res-t))res=s;if(s<t)l++;else r--;}}cout<<res<<endl;return 0;}
