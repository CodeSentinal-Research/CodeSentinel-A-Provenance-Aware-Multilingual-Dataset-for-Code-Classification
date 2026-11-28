#include<bits/stdc++.h>
using namespace std;
int main(){int n,t;cin>>n>>t;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];sort(a.begin(),a.end());long long res=0,mod=1e9+7;for(int l=0;l<n;l++){int r=upper_bound(a.begin(),a.end(),t-a[l])-a.begin()-1;if(r>l){long long p=1;for(int i=0;i<r-l;i++)p=(p*2)%mod;res=(res+p)%mod;}}cout<<res<<endl;return 0;}
