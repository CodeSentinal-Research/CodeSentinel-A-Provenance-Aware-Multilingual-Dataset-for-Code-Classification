#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>jmp(n+1,0);int l;cin>>l;for(int i=0;i<l;i++){int u,v;cin>>u>>v;jmp[u]=v-u;}int s;cin>>s;for(int i=0;i<s;i++){int u,v;cin>>u>>v;jmp[u]=v-u;}vector<int>dist(n+1,1e9);dist[1]=0;queue<int>q;q.push(1);while(!q.empty()){int u=q.front();q.pop();if(u==n)break;for(int i=1;i<=6;i++){int v=u+i;if(v>n)break;v+=jmp[v];if(dist[v]==1e9){dist[v]=dist[u]+1;q.push(v);}}}cout<<dist[n]<<endl;return 0;}
