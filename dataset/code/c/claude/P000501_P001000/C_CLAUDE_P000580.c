#include <stdio.h>
#include <stdlib.h>
typedef struct N{int d;struct N*nx;}N;
N* nn(int d){N*n=(N*)malloc(sizeof(N));n->d=d;n->nx=NULL;return n;}
int main(){int n;scanf("%d",&n);N*h=NULL,*t=NULL;for(int i=0;i<n;i++){int v;scanf("%d",&v);N*nd=nn(v);if(!h)h=t=nd;else{t->nx=nd;t=nd;}}N*s=h,*f=h;while(f&&f->nx){s=s->nx;f=f->nx->nx;}printf("%d\n",s->d);return 0;}
