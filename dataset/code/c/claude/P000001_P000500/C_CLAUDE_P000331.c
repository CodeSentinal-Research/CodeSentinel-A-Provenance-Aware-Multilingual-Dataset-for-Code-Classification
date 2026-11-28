#include<stdio.h>
#include<string.h>
int main(){
    int n,m;scanf("%d %d",&n,&m);
    int res[n],stk[m];for(int i=0;i<n;i++)res[i]=0;int top=0,prev=0;
    for(int k=0;k<m;k++){
        char log[100];scanf("%s",log);int fid,time;char typ[10];
        sscanf(log,"%d:%[^:]:%d",&fid,typ,&time);
        if(strcmp(typ,"start")==0){if(top)res[stk[top-1]]+=time-prev;stk[top++]=fid;prev=time;}
        else{res[stk[--top]]+=time-prev+1;prev=time+1;}
    }
    for(int i=0;i<n;i++)printf("%d%c",res[i],i<n-1?' ':'\n');
}
