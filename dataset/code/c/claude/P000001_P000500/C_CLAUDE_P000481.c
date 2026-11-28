#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){int n;scanf("%d",&n);int stk[1001],top=0;for(int i=0;i<n;i++){char op[20];scanf("%s",op);if(strcmp(op,"+")==0)stk[top]=stk[top-1]+stk[top-2],top++;else if(strcmp(op,"D")==0)stk[top]=stk[top-1]*2,top++;else if(strcmp(op,"C")==0)top--;else stk[top++]=atoi(op);}long long s=0;for(int i=0;i<top;i++)s+=stk[i];printf("%lld\n",s);}
