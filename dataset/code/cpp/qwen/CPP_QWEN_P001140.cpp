#include<bits/stdc++.h>
using namespace std;
int main(){int n,w;cin>>n>>w;vector<int>wt(n),val(n);for(int i=0;i<n;i++)cin>>wt[i]>>val[i];vector<long long>f(w+1,0);for(int i=0;i<n;i++)for(int j=wt[i];j<=w;j++)f[j]=max(f[j],f[j-wt[i]]+val[i]);cout<<f[w]<<endl;return 0;}
