#include<stdio.h>
#include<string.h>
int pal(char*s,int l,int r){while(l<r)if(s[l++]!=s[r--])return 0;return 1;}
int main(){char s[100001];scanf("%s",s);int n=strlen(s),l=0,r=n-1;while(l<r&&s[l]==s[r]){l++;r--;}printf("%s\n",(l>=r||pal(s,l+1,r)||pal(s,l,r-1))?"Yes":"No");}
