#include<bits/stdc++.h>
using namespace std;
int main(){int n,amt;cin>>n>>amt;vector<int>c(n);for(int i=0;i<n;i++)cin>>c[i];vector<int>f(amt+1,1e9);f[0]=0;for(int i=1;i<=amt;i++)for(int x:c)if(i>=x&&f[i-x]!=1e9)f[i]=min(f[i],f[i-x]+1);cout<<(f[amt]==1e9?-1:f[amt])<<endl;return 0;}
