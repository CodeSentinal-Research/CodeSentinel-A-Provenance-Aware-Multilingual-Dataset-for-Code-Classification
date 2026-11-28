#include<stdio.h>
#include<string.h>
int main(){char s[10001];fgets(s,sizeof(s),stdin);char*words[1001];int n=0;char*p=strtok(s," \n");while(p){words[n++]=p;p=strtok(NULL," \n");}for(int i=n-1;i>=0;i--){printf("%s",words[i]);if(i>0)printf(" ");}printf("\n");}
