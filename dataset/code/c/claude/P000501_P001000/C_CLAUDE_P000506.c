#include<stdio.h>
#include<ctype.h>
char s[100001];int idx;
long long calc(){
    long long stk[10001];int top=0;long long num=0;char sign='+';
    while(s[idx]){
        char c=s[idx++];
        if(isdigit(c))num=num*10+(c-'0');
        else if(c=='(')num=calc();
        if((!isdigit(c)&&c!=' ')||!s[idx]){
            if(sign=='+')stk[top++]=num;else if(sign=='-')stk[top++]=-num;
            else if(sign=='*'){long long v=stk[--top]*num;stk[top++]=v;}
            else{long long v=(long long)(stk[--top]/num);stk[top++]=v;}
            if(c==')')break;
            sign=c;num=0;
        }
    }
    long long r=0;for(int i=0;i<top;i++)r+=stk[i];return r;
}
int main(){fgets(s,sizeof(s),stdin);s[strcspn(s,"\n")]=0;idx=0;printf("%lld\n",calc());}
