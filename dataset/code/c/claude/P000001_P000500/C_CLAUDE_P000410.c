#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char recs[1001][1001];for(int i=0;i<n;i++){fgets(recs[i],sizeof(recs[i]),stdin);recs[i][strcspn(recs[i],"\n")]=0;}char q[101];fgets(q,sizeof(q),stdin);q[strcspn(q,"\n")]=0;int found=0,ql=strlen(q);for(int i=0;i<n;i++){char tmp[1001];strcpy(tmp,recs[i]);char*sp=strchr(tmp,' ');if(sp)*sp=0;int tl=strlen(tmp);if(tl>=(int)ql&&strcmp(tmp+tl-ql,q)==0){printf("%s\n",recs[i]);found=1;}}if(!found)printf("No Products Found\n");}
