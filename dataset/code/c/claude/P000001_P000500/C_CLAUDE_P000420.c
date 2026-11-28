#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char recs[1001][1001];for(int i=0;i<n;i++){fgets(recs[i],sizeof(recs[i]),stdin);recs[i][strcspn(recs[i],"\n")]=0;}char q[201];fgets(q,sizeof(q),stdin);q[strcspn(q,"\n")]=0;int found=0;for(int i=0;i<n;i++){char tmp[1001];strcpy(tmp,recs[i]);char*f=strtok(tmp," ");for(int k=0;k<1;k++)if(f)f=strtok(NULL," ");if(f&&strcmp(f,q)==0){printf("%s\n",recs[i]);found=1;}}if(!found)printf("No Slots Found\n");}
