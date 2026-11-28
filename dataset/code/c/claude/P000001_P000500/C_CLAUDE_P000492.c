#include<stdio.h>
#include<string.h>
int main(){char path[10001];fgets(path,sizeof(path),stdin);path[strcspn(path,"\n")]=0;char*stk[1001];int top=0;char*p=strtok(path,"/");while(p){if(strcmp(p,"..")==0){if(top>0)top--;}else if(strcmp(p,".")!=0&&strlen(p)>0)stk[top++]=p;p=strtok(NULL,"/");}printf("/");for(int i=0;i<top;i++){printf("%s",stk[i]);if(i<top-1)printf("/");}printf("\n");}
