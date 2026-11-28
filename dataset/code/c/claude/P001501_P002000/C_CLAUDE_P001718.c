#include <stdio.h>
#include <stdlib.h>
typedef struct N{int d;struct N*l,*r;}N;
N* nn(int d){N*n=(N*)malloc(sizeof(N));n->d=d;n->l=n->r=NULL;return n;}
N* ins(N*r,int d){if(!r)return nn(d);if(d<r->d)r->l=ins(r->l,d);else if(d>r->d)r->r=ins(r->r,d);return r;}
N* srch(N*r,int k){if(!r||r->d==k)return r;if(k<r->d)return srch(r->l,k);return srch(r->r,k);}
void in(N*r){if(!r)return;in(r->l);printf("%d ",r->d);in(r->r);}
int main(){int n;scanf("%d",&n);N*r=NULL;for(int i=0;i<n;i++){int v;scanf("%d",&v);r=ins(r,v);}int k;scanf("%d",&k);printf("%s\n",srch(r,k)?"Found":"Not Found");in(r);printf("\n");return 0;}
