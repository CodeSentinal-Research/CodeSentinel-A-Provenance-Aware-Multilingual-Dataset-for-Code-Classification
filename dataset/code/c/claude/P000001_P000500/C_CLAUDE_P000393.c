#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char recs[1001][1001];for(int i=0;i<n;i++){fgets(recs[i],sizeof(recs[i]),stdin);recs[i][strcspn(recs[i],"\n")]=0;}char pfx[101];fgets(pfx,sizeof(pfx),stdin);pfx[strcspn(pfx,"\n")]=0;int pl=strlen(pfx),found=0;for(int i=0;i<n;i++)if(strncmp(recs[i],pfx,pl)==0){printf("%s\n",recs[i]);found=1;}if(!found)printf("No Records Found\n");}
