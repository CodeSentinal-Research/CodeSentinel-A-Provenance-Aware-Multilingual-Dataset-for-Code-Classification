#include<stdio.h>
#include<stdlib.h>
typedef struct{int v,i;}P;
int cmp(const void*a,const void*b){return ((P*)a)->v-((P*)b)->v;}
int main(){int n;scanf("%d",&n);P p[n];for(int i=0;i<n;i++){scanf("%d",&p[i].v);p[i].i=i;}int orig[n];for(int i=0;i<n;i++)orig[i]=p[i].i;qsort(p,n,sizeof(P),cmp);int pos[n];for(int i=0;i<n;i++)pos[p[i].i]=i;int vis[n];for(int i=0;i<n;i++)vis[i]=0;int sw=0;for(int i=0;i<n;i++){if(vis[i]||pos[i]==i)continue;int j=i,c=0;while(!vis[j]){vis[j]=1;j=pos[j];c++;}sw+=c-1;}printf("%d\n",sw);}
