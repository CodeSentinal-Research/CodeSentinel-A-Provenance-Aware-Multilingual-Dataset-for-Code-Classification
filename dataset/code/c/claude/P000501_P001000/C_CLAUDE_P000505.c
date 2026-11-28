#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){char s[100001];fgets(s,sizeof(s),stdin);s[strcspn(s,"\n")]=0;
long long stk[100001];int top=0;long long num=0;char sign='+';
for(int i=0;s[i]||sign;i++){
    if(isdigit(s[i])){num=num*10+(s[i]-'0');if(s[i+1]&&!isspace(s[i+1])&&!isdigit(s[i+1]));}
    if((!isdigit(s[i])&&!isspace(s[i]))||!s[i]){
        if(sign=='+')stk[top++]=num;
        else if(sign=='-')stk[top++]=-num;
        else if(sign=='*'){long long v=stk[--top]*num;stk[top++]=v;}
        else{long long v=(long long)(stk[--top]/num);stk[top++]=v;}
        sign=s[i];num=0;if(!s[i])break;
    }
}long long res=0;for(int i=0;i<top;i++)res+=stk[i];printf("%lld\n",res);}
