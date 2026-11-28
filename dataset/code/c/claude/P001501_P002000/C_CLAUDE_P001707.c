#include <stdio.h>
#include <stdlib.h>
typedef struct N{int d;struct N*l,*r;}N;
N* nn(int d){N*n=(N*)malloc(sizeof(N));n->d=d;n->l=n->r=NULL;return n;}
N* ins(N*r,int d){if(!r)return nn(d);if(d<r->d)r->l=ins(r->l,d);else r->r=ins(r->r,d);return r;}
void bfs(N*r){if(!r)return;N*q[100001];int fr=0,re=0;q[re++]=r;while(fr<re){N*c=q[fr++];printf("%d ",c->d);if(c->l)q[re++]=c->l;if(c->r)q[re++]=c->r;}printf("\n");}
int main(){int n;scanf("%d",&n);N*r=NULL;for(int i=0;i<n;i++){int v;scanf("%d",&v);r=ins(r,v);}bfs(r);return 0;}
