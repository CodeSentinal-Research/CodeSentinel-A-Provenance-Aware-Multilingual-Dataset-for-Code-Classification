#include<bits/stdc++.h>
using namespace std;
int p[100005];int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
int main(){int n,m;cin>>n>>m;vector<tuple<int,int,int>>e(m);for(int i=0;i<m;i++){int t,u,v;cin>>t>>u>>v;e[i]={t,u,v};}sort(e.begin(),e.end(),greater<>());int res=0;for(int t=3;t>=1;t--){for(int i=1;i<=n;i++)p[i]=i;int c1=n,c2=n;for(auto&[type,u,v]:e){if(type==3||type==t){if(f(u)!=f(v)){p[f(u)]=f(v);if(type==3){c1--;c2--;}else if(t==1)c1--;else c2--;}}}}for(auto&[type,u,v]:e){if(type==1){if(f(u)!=f(v)){p[f(u)]=f(v);c1--;}}else if(type==2){if(f(u)!=f(v)){p[f(u)]=f(v);c2--;}}}cout<<((c1==1&&c2==1)?m-(n-1):-1)<<endl;return 0;}
