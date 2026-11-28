#include<stdio.h>
#include<ctype.h>
int main(){char s[10001];scanf("%s",s);char stk[10001];int top=0;
for(int i=0;s[i];i++){
    if(isdigit(s[i])){if(top>0&&!isdigit(stk[top-1]))top--;}
    else stk[top++]=s[i];}
stk[top]=0;printf("%s\n",stk);}
