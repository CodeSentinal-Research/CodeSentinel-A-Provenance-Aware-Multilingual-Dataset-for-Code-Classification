#include <stdio.h>
#include <stdlib.h>
typedef struct N{int d;struct N*nx;}N;
int cyc(N*h){N*s=h,*f=h;while(f&&f->nx){s=s->nx;f=f->nx->nx;if(s==f)return 1;}return 0;}
int main(){int n,cp;scanf("%d %d",&n,&cp);N*ns[n+1];N*h=NULL;for(int i=0;i<n;i++){int v;scanf("%d",&v);ns[i]=(N*)malloc(sizeof(N));ns[i]->d=v;ns[i]->nx=NULL;if(i>0)ns[i-1]->nx=ns[i];if(i==0)h=ns[0];}if(cp>=0)ns[n-1]->nx=ns[cp];printf("%s\n",cyc(h)?"Cycle Detected":"No Cycle");return 0;}
