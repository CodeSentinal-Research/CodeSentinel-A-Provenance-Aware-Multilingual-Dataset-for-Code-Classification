#include <stdio.h>
int g[101][101],n,m,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
void dfs(int r,int c,int o,int nw){if(r<0||r>=n||c<0||c>=m||g[r][c]!=o)return;g[r][c]=nw;for(int d=0;d<4;d++)dfs(r+dx[d],c+dy[d],o,nw);}
int main(){int sr,sc,nw;scanf("%d %d",&n,&m);for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&g[i][j]);scanf("%d %d %d",&sr,&sc,&nw);int o=g[sr][sc];if(o!=nw)dfs(sr,sc,o,nw);for(int i=0;i<n;i++){for(int j=0;j<m;j++)printf("%d%s",g[i][j],j<m-1?" ":"\n");}return 0;}
