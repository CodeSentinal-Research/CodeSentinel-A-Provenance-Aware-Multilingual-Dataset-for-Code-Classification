#include<bits/stdc++.h>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int l=0,z=0,res=0;for(int r=0;r<n;r++){if(a[r]==0)z++;while(z>k){if(a[l]==0)z--;l++;}res=max(res,r-l+1);}cout<<res<<endl;return 0;}
