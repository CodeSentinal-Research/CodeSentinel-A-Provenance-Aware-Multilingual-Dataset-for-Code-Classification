#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d",&n);char words[1001][101],s[101];for(int i=0;i<n;i++)scanf("%s",words[i]);scanf("%s",s);int cnt=0;for(int i=0;i<n;i++)if(strncmp(s,words[i],strlen(words[i]))==0)cnt++;printf("%d\n",cnt);}
