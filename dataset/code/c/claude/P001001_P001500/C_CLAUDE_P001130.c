#include <stdio.h>
#include <string.h>
#define MX 1001
int adj[MX][MX],vis[MX],q[MX*MX],fr,re;
void bfs(int s,int n){vis[s]=1;q[re++]=s;while(fr<re){int u=q[fr++];printf("%d ",u);for(int v=1;v<=n;v++)if(adj[u][v]&&!vis[v]){vis[v]=1;q[re++]=v;}}printf("\n");}
int main(){int n,m,s;scanf("%d %d",&n,&m);memset(adj,0,sizeof(adj));memset(vis,0,sizeof(vis));fr=re=0;for(int i=0;i<m;i++){int u,v;scanf("%d %d",&u,&v);adj[u][v]=adj[v][u]=1;}scanf("%d",&s);bfs(s,n);return 0;}
