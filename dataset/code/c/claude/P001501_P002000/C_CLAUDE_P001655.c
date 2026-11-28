#include <stdio.h>
#include <stdlib.h>
typedef struct N{int d;struct N*nx;}N;
N* ins(N*h,int d){N*nd=(N*)malloc(sizeof(N));nd->d=d;nd->nx=NULL;if(!h)return nd;N*c=h;while(c->nx)c=c->nx;c->nx=nd;return h;}
int main(){int n;scanf("%d",&n);N*h=NULL;for(int i=0;i<n;i++){int v;scanf("%d",&v);h=ins(h,v);}N*c=h;while(c){printf("%d",c->d);if(c->nx)printf(" -> ");c=c->nx;}printf("\n");return 0;}
