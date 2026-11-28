#include<stdio.h>
#include<string.h>
void proc(char*s,char*out){int top=0;for(int i=0;s[i];i++){if(s[i]=='#'){if(top>0)top--;}else out[top++]=s[i];}out[top]=0;}
int main(){char s[10001],t[10001],ps[10001],pt[10001];scanf("%s %s",s,t);proc(s,ps);proc(t,pt);printf("%s\n",strcmp(ps,pt)==0?"true":"false");}
