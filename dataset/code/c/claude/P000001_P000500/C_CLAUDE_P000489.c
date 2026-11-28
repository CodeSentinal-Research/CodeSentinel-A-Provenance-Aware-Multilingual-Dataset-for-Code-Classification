#include<stdio.h>
#include<string.h>
int stk[10001],mstk[10001],top=0;
int main(){int n;scanf("%d",&n);while(n--){char cmd[10];scanf("%s",cmd);if(!strcmp(cmd,"push")){int x;scanf("%d",&x);stk[top]=x;mstk[top]=top==0?x:(x<mstk[top-1]?x:mstk[top-1]);top++;}else if(!strcmp(cmd,"pop"))top--;else if(!strcmp(cmd,"top"))printf("%d\n",stk[top-1]);else printf("%d\n",mstk[top-1]);}}
