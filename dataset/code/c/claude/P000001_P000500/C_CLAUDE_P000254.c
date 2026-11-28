#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){char s[1001];scanf("%s",s);char*v="aeiouAEIOU";int cnt=0;for(int i=0;s[i];i++)if(isalpha(s[i])&&!strchr(v,s[i]))cnt++;printf("%d\n",cnt);}
