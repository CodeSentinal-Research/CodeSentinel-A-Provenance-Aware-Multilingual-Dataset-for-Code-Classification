#include <stdio.h>
int n, m;
void gen(int x, int y, char *path, int pi) { if(x==n-1 && y==m-1) { path[pi]='\0'; printf("%s\n",path); return; } for(int i=1;i<=m-1-y;i++) { sprintf(path+pi,"H%d",i); gen(x,y+i,path,pi+2); } for(int i=1;i<=n-1-x;i++) { sprintf(path+pi,"V%d",i); gen(x+i,y,path,pi+2); } for(int i=1;i<=n-1-x && i<=m-1-y;i++) { sprintf(path+pi,"D%d",i); gen(x+i,y+i,path,pi+2); } }
int main() { scanf("%d%d",&n,&m); char path[100]; gen(0,0,path,0); return 0; }
