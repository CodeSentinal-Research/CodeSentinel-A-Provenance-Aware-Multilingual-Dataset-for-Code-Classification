#include<bits/stdc++.h>
using namespace std;
int main(){int n,k,x;cin>>n>>k>>x;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int idx=lower_bound(a.begin(),a.end(),x)-a.begin();int l=max(0,idx-k/2),r=min(n-1,l+k-1);l=max(0,r-k+1);for(int i=l;i<=r;i++)cout<<a[i]<<" ";cout<<endl;return 0;}
