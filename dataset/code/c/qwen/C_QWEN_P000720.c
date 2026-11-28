#include <stdio.h>
#include <string.h>
void gen(char *s, int i, long long curr, long long prev, char *expr, int ei, int t) { if(i==strlen(s)) { if(curr==t) { expr[ei]='\0'; printf("%s\n",expr); } return; } for(int j=i;j<strlen(s);j++) { if(j>i && s[i]=='0') break; long long num=0; for(int k=i;k<=j;k++) num=num*10+(s[k]-'0'); expr[ei]='+'; sprintf(expr+ei+1,"%lld",num); gen(s,j+1,curr+num,num,expr,ei+1+j-i+1,t); expr[ei]='-'; sprintf(expr+ei+1,"%lld",num); gen(s,j+1,curr-num,-num,expr,ei+1+j-i+1,t); expr[ei]='*'; sprintf(expr+ei+1,"%lld",num); gen(s,j+1,curr-prev+prev*num,num*prev,expr,ei+1+j-i+1,t); } }
int main() { char s[11]; int t; scanf("%s%d",s,&t); char expr[25]; gen(s,0,0,0,expr,0,t); return 0; }
