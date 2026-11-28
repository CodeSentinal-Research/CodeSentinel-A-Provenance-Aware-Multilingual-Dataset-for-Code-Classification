#include<stdio.h>
#include<string.h>
void rev(char*s,int l,int r){while(l<r){char t=s[l];s[l]=s[r];s[r]=t;l++;r--;}}
int main(){char s[10001];fgets(s,sizeof(s),stdin);s[strcspn(s,"\n")]=0;
int n=strlen(s),stk[10001],top=0;char res[10001];int ri=0;
for(int i=0;i<n;i++){
    if(s[i]=='(') stk[top++]=ri;
    else if(s[i]==')'){int st=stk[--top];rev(res,st,ri-1);}
    else res[ri++]=s[i];
}res[ri]=0;printf("%s\n",res);}
