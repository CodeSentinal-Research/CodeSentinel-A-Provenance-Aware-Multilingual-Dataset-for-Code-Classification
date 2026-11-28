#include <stdio.h>
#include <stdlib.h>
typedef struct N{int d;struct N*l,*r;}N;
N* nn(int d){N*n=(N*)malloc(sizeof(N));n->d=d;n->l=n->r=NULL;return n;}
N* ins(N*r,int d){if(!r)return nn(d);if(d<r->d)r->l=ins(r->l,d);else r->r=ins(r->r,d);return r;}
int ht(N*r){if(!r)return 0;int l=ht(r->l),ri=ht(r->r);return 1+(l>ri?l:ri);}
int main(){int n;scanf("%d",&n);N*r=NULL;for(int i=0;i<n;i++){int v;scanf("%d",&v);r=ins(r,v);}printf("%d\n",ht(r));return 0;}
