#include<stdio.h>
#include<string.h>
int main(){char s[10001];int k;scanf("%s %d",s,&k);char stk[10001];int cnt[10001],top=0;for(int i=0;s[i];i++){if(top>0&&stk[top-1]==s[i]){cnt[top-1]++;if(cnt[top-1]==k)top--;}else{stk[top]=s[i];cnt[top]=1;top++;}}char res[10001]="";for(int i=0;i<top;i++)for(int j=0;j<cnt[i];j++){int l=strlen(res);res[l]=stk[i];res[l+1]=0;}printf("%s\n",res);}
