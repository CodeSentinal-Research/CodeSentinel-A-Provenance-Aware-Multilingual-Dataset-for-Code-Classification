#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char recs[1001][10001];for(int i=0;i<n;i++){fgets(recs[i],sizeof(recs[i]),stdin);recs[i][strcspn(recs[i],"\n")]=0;}char q[1001];fgets(q,sizeof(q),stdin);q[strcspn(q,"\n")]=0;for(int i=0;i<n;i++){char tmp[10001];strcpy(tmp,recs[i]);char*f=strtok(tmp," ");for(int k=0;k<0;k++)if(f)f=strtok(NULL," ");if(f&&strcmp(f,q)==0){printf("%s\n",recs[i]);return 0;}}printf("Product Not Found\n");}
