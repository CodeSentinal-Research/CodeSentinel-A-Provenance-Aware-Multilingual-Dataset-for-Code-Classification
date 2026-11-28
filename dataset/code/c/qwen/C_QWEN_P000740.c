#include <stdio.h>
int n, m;
void gen(int x, int y, char *path, int pi) { if(x==n-1 && y==m-1) { path[pi]='\0'; printf("%s\n",path); return; } if(y+1<m) { path[pi]='H'; gen(x,y+1,path,pi+1); } if(x+1<n) { path[pi]='V'; gen(x+1,y,path,pi+1); } if(x+1<n && y+1<m) { path[pi]='D'; gen(x+1,y+1,path,pi+1); } }
int main() { scanf("%d%d",&n,&m); char path[100]; gen(0,0,path,0); return 0; }
