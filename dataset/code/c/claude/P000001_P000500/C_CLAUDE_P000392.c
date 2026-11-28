#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char files[1001][1001];for(int i=0;i<n;i++){fgets(files[i],sizeof(files[i]),stdin);files[i][strcspn(files[i],"\n")]=0;}char ext[101];fgets(ext,sizeof(ext),stdin);ext[strcspn(ext,"\n")]=0;int found=0;for(int i=0;i<n;i++){char*dot=strrchr(files[i],".");if(dot&&strcmp(dot+1,ext)==0){printf("%s\n",files[i]);found=1;}}if(!found)printf("No Records Found\n");}
