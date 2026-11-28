#include<stdio.h>
#include<string.h>
int main(){char s[10001];int k;scanf("%s %d",s,&k);int n=strlen(s);char stk[10001];int top=0;for(int i=0;s[i];i++){while(k>0&&top>0&&stk[top-1]>s[i]){top--;k--;}stk[top++]=s[i];}top-=k;int start=0;while(start<top-1&&stk[start]=='0')start++;stk[top]=0;printf("%s\n",top==0?"0":stk+start);}
