#include<stdio.h>
#include<string.h>
int main(){char s[10001];scanf("%s",s);int cnt[26]={},seen[26]={};for(int i=0;s[i];i++)cnt[s[i]-'a']++;char stk[10001];int top=0;for(int i=0;s[i];i++){int c=s[i]-'a';cnt[c]--;if(seen[c])continue;while(top>0&&stk[top-1]>s[i]&&cnt[stk[top-1]-'a']>0){seen[stk[top-1]-'a']=0;top--;}stk[top++]=s[i];seen[c]=1;}stk[top]=0;printf("%s\n",stk);}
