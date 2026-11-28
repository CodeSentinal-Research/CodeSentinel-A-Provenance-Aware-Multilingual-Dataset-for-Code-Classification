#include<stdio.h>
int main(){char s[10001];scanf("%s",s);int stk[10001],top=0;stk[top++]=0;
for(int i=0;s[i];i++){
    if(s[i]=='(')stk[top++]=0;
    else{int v=stk[--top];stk[top-1]+=v?2*v:1;}
}printf("%d\n",stk[0]);}
