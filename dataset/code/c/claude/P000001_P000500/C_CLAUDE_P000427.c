#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){int n;scanf("%d",&n);char recs[1001][1001];for(int i=0;i<n;i++){scanf(" ");fgets(recs[i],sizeof(recs[i]),stdin);recs[i][strcspn(recs[i],"\n")]=0;}double mp;scanf("%lf",&mp);int found=0;for(int i=0;i<n;i++){char tmp[1001];strcpy(tmp,recs[i]);char*tok=strtok(tmp," ");char*last=NULL;while(tok){last=tok;tok=strtok(NULL," ");}if(last&&atof(last)>=mp){printf("%s\n",recs[i]);found=1;}}if(!found)printf("No Products Found\n");}
