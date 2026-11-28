#include<stdio.h>
#include<string.h>
int res[1000],rc=0;
void ways(char*s,int len,int*out,int*oc){
    int any=0;
    for(int i=0;i<len;i++){
        if(s[i]!='+'&&s[i]!='-'&&s[i]!='*')continue;
        any=1;
        int L[100],lc=0,R[100],rc2=0;
        ways(s,i,L,&lc);ways(s+i+1,len-i-1,R,&rc2);
        for(int a=0;a<lc;a++)for(int b=0;b<rc2;b++){
            if(s[i]=='+')out[(*oc)++]=L[a]+R[b];
            else if(s[i]=='-')out[(*oc)++]=L[a]-R[b];
            else out[(*oc)++]=L[a]*R[b];
        }
    }
    if(!any){char tmp[20];strncpy(tmp,s,len);tmp[len]=0;out[(*oc)++]=atoi(tmp);}
}
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){char expr[1001];scanf("%s",expr);int out[1000],oc=0;ways(expr,strlen(expr),out,&oc);qsort(out,oc,sizeof(int),cmp);for(int i=0;i<oc;i++)printf("%d%c",out[i],i<oc-1?' ':'\n');}
