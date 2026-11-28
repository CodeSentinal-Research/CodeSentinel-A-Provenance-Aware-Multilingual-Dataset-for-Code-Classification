#include<stdio.h>
#include<string.h>
int main(){char text[10001],broken[30];fgets(text,sizeof(text),stdin);fgets(broken,sizeof(broken),stdin);broken[strcspn(broken,"\n")]=0;int cnt=0,inW=0,skip=0;for(int i=0;text[i];i++){if(text[i]==' '||text[i]=='\n'){if(inW&&!skip)cnt++;inW=0;skip=0;}else{if(!inW)inW=1;if(strchr(broken,text[i]))skip=1;}}if(inW&&!skip)cnt++;printf("%d\n",cnt);}
