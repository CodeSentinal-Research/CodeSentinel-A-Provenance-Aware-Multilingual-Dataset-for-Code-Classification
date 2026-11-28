#include <stdio.h>
int n, maze[10][10], visited[10][10];
void solve(int x, int y, char *path, int pi) { if(x==n-1 && y==n-1) { path[pi]='\0'; printf("%s\n",path); return; } int dx[]={1,0,0,-1}, dy[]={0,-1,1,0}; char dir[]={'D','L','R','U'}; for(int i=0;i<4;i++) { int nx=x+dx[i], ny=y+dy[i]; if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny] && maze[nx][ny]==1) { visited[nx][ny]=1; path[pi]=dir[i]; solve(nx,ny,path,pi+1); visited[nx][ny]=0; } } }
int main() { scanf("%d",&n); for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&maze[i][j]); char path[100]; visited[0][0]=1; solve(0,0,path,0); return 0; }
