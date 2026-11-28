#include<bits/stdc++.h>
using namespace std;
int p[1005];int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
int main(){int n;cin>>n;for(int i=1;i<=n;i++)p[i]=i;for(int i=0;i<n;i++){int u,v;cin>>u>>v;if(f(u)==f(v)){cout<<u<<" "<<v<<endl;return 0;}p[f(u)]=f(v);}return 0;}
