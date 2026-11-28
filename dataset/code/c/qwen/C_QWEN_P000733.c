#include <stdio.h>
int v, e, m, adj[20][20];
int solve(int i, int *color) { if(i==v) return 1; for(int c=1;c<=m;c++) { int ok=1; for(int j=0;j<v;j++) if(adj[i][j] && color[j]==c) { ok=0; break; } if(ok) { color[i]=c; if(solve(i+1,color)) return 1; color[i]=0; } } return 0; }
int main() { scanf("%d%d",&v,&e); for(int i=0;i<e;i++) { int u,w; scanf("%d%d",&u,&w); adj[u][w]=adj[w][u]=1; } scanf("%d",&m); int color[v]={0}; printf("%s\n",solve(0,color)?"true":"false"); return 0; }
