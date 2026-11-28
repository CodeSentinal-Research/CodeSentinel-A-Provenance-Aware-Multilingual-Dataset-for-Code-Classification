#include<stdio.h>
int main(){char s[10001];fgets(s,sizeof(s),stdin);int cnt=0,inW=0;for(int i=0;s[i];i++){if(s[i]!= ' '&&s[i]!='\n'){if(!inW){cnt++;inW=1;}}else inW=0;}printf("%d\n",cnt);}
