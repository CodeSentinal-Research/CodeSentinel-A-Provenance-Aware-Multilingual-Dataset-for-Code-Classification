#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){char line[100001];fgets(line,sizeof(line),stdin);
long long stk[10001];int top=0;
char*tok=strtok(line," \n");
while(tok){
    if(strcmp(tok,"+")==0){long long b=stk[--top],a=stk[--top];stk[top++]=a+b;}
    else if(strcmp(tok,"-")==0){long long b=stk[--top],a=stk[--top];stk[top++]=a-b;}
    else if(strcmp(tok,"*")==0){long long b=stk[--top],a=stk[--top];stk[top++]=a*b;}
    else if(strcmp(tok,"/")==0){long long b=stk[--top],a=stk[--top];stk[top++]=(long long)(a/b);}
    else stk[top++]=atoll(tok);
    tok=strtok(NULL," \n");
}printf("%lld\n",stk[0]);}
