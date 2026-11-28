#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int mn=a[0],res=0;for(int i=1;i<n;i++){res=max(res,a[i]-mn);mn=min(mn,a[i]);}cout<<res<<endl;return 0;}
