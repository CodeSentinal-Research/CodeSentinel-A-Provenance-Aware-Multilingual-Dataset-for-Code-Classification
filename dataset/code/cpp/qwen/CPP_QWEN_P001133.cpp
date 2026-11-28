#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>c(n);for(int i=0;i<n;i++)cin>>c[i];vector<long long>f(n+1);for(int i=2;i<=n;i++)f[i]=min(f[i-1]+c[i-1],f[i-2]+c[i-2]);cout<<f[n]<<endl;return 0;}
