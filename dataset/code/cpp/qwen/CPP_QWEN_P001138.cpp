#include<bits/stdc++.h>
using namespace std;
int main(){int n,amt;cin>>n>>amt;vector<int>c(n);for(int i=0;i<n;i++)cin>>c[i];vector<long long>f(amt+1,0);f[0]=1;for(int x:c)for(int i=x;i<=amt;i++)f[i]+=f[i-x];cout<<f[amt]<<endl;return 0;}
