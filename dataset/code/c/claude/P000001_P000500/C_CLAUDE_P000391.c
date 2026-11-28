#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char recs[1001][1001];for(int i=0;i<n;i++){fgets(recs[i],sizeof(recs[i]),stdin);recs[i][strcspn(recs[i],"\n")]=0;}double t;scanf("%lf",&t);int found=0;for(int i=0;i<n;i++){char tmp[1001];strcpy(tmp,recs[i]);char*last=tmp;char*p=strtok(tmp," ");while(p){last=p;p=strtok(NULL," ");}if(atof(last)>=t){printf("%s\n",recs[i]);found=1;}}if(!found)printf("No Records Found\n");}
