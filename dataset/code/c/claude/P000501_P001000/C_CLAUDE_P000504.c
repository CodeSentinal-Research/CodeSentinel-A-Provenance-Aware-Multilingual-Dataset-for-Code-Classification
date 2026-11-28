#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d",&n);int res[101]={},stk[101],top=0,prev=0;
for(int i=0;i<n;i++){
    int fid,t;char typ[10];scanf("%d:%[^:]:%d",&fid,typ,&t);
    if(strcmp(typ,"start")==0){if(top>0)res[stk[top-1]]+=t-prev;stk[top++]=fid;prev=t;}
    else{res[stk[--top]]+=t-prev+1;prev=t+1;}
}for(int i=0;i<n;i++)printf("%d%c",res[i],i<n-1?' ':'\n');}
