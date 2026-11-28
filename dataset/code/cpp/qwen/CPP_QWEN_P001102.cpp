#include<bits/stdc++.h>
using namespace std;
int p[100005];int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
int main(){int n,m;cin>>n>>m;vector<tuple<int,int,int>>e(m);for(int i=0;i<m;i++){int u,v,w;cin>>u>>v>>w;e[i]={w,u,v};}sort(e.begin(),e.end());for(int i=1;i<=n;i++)p[i]=i;long long res=0;int cnt=0;for(auto&[w,u,v]:e){if(f(u)!=f(v)){p[f(u)]=f(v);res+=w;cnt++;}}cout<<(cnt==n-1?res:-1)<<endl;return 0;}
