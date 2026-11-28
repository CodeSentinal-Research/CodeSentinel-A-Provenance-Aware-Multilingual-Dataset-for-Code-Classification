#include<bits/stdc++.h>
using namespace std;
int p[160005];int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
int main(){int n;cin>>n;vector<string>g(n);for(int i=0;i<n;i++)cin>>g[i];for(int i=0;i<=4*n;i++)p[i]=i;auto idx=[&](int r,int c,int k){return (r*n+c)*4+k;};for(int i=0;i<n;i++)for(int j=0;j<n;j++){if(g[i][j]!='\\'){p[f(idx(i,j,0))]=f(idx(i,j,1));p[f(idx(i,j,2))]=f(idx(i,j,3));}if(g[i][j]!='/'){p[f(idx(i,j,0))]=f(idx(i,j,3));p[f(idx(i,j,1))]=f(idx(i,j,2));}if(j+1<n)p[f(idx(i,j,1))]=f(idx(i,j+1,3));if(i+1<n)p[f(idx(i,j,2))]=f(idx(i+1,j,0));}int cnt=0;for(int i=0;i<4*n*n;i++)if(f(i)==i)cnt++;cout<<cnt<<endl;return 0;}
