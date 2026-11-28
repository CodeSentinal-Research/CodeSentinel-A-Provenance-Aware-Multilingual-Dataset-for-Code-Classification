#include<stdio.h>
#include<stdlib.h>
typedef struct{int id,d,p;}J;
int cmp(const void*a,const void*b){return ((J*)b)->p-((J*)a)->p;}
int main(){int n;scanf("%d",&n);J j[n];int md=0;for(int i=0;i<n;i++){scanf("%d %d %d",&j[i].id,&j[i].d,&j[i].p);if(j[i].d>md)md=j[i].d;}qsort(j,n,sizeof(J),cmp);int slot[md+1];for(int i=0;i<=md;i++)slot[i]=-1;int cnt=0,prof=0;for(int i=0;i<n;i++){for(int t=j[i].d;t>0;t--){if(slot[t]==-1){slot[t]=j[i].id;cnt++;prof+=j[i].p;break;}}}printf("%d %d\n",cnt,prof);}
