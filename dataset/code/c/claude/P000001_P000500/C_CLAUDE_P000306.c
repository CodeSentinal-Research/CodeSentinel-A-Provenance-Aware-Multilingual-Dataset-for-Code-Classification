#include<stdio.h>
int main(){
    char expr[10001];fgets(expr,sizeof(expr),stdin);
    long long stk[10001];int top=0;long long num=0;char op='+';
    for(int i=0;expr[i];i++){
        char c=expr[i];
        if(c>='0'&&c<='9')num=num*10+(c-'0');
        if((c!=' '&&!(c>='0'&&c<='9'))||(!expr[i+1])||expr[i+1]=='\n'){
            if(op=='+')stk[top++]=num;
            else if(op=='-')stk[top++]=-num;
            else if(op=='*'){top--;stk[top]=stk[top]*num;top++;}
            else if(op=='/'){top--;long long v=stk[top];stk[top]=(v<0?-((-v)/num):(v/num));top++;}
            op=c;num=0;
        }
    }
    long long res=0;for(int i=0;i<top;i++)res+=stk[i];printf("%lld\n",res);
}
