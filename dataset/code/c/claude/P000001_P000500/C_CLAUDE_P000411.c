#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char recs[1001][1001];for(int i=0;i<n;i++){fgets(recs[i],sizeof(recs[i]),stdin);recs[i][strcspn(recs[i],"\n")]=0;}char kw[201];fgets(kw,sizeof(kw),stdin);kw[strcspn(kw,"\n")]=0;int found=0;for(int i=0;i<n;i++)if(strstr(recs[i],kw)){printf("%s\n",recs[i]);found=1;}if(!found)printf("No Records Found\n");}
