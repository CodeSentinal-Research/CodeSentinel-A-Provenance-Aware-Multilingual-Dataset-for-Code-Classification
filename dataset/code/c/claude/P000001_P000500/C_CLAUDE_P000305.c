#include<stdio.h>
#include<string.h>
int main(){
    char expr[10001];fgets(expr,sizeof(expr),stdin);
    int stk[10001],top=0,num=0,sign=1,res=0;
    for(int i=0;expr[i];i++){
        char c=expr[i];
        if(c>='0'&&c<='9') num=num*10+(c-'0');
        else if(c=='+'||c=='-'){res+=sign*num;num=0;sign=(c=='+'?1:-1);}
        else if(c=='('){stk[top++]=res;stk[top++]=sign;res=0;sign=1;}
        else if(c==')'){res+=sign*num;num=0;sign=stk[--top];res=res*sign+stk[--top];sign=1;}
    }
    res+=sign*num;printf("%d\n",res);
}
