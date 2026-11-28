#include <stdio.h>
int n, m, grid[15][15];
int solve(int x, int y) { if(x==n-1 && y==m-1) return 1; if(x>=n || y>=m || grid[x][y]==0) return 0; return solve(x+1,y)+solve(x,y+1); }
int main() { scanf("%d%d",&n,&m); for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&grid[i][j]); printf("%d\n",solve(0,0)); return 0; }
