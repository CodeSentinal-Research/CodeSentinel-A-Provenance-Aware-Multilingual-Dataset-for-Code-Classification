#include<stdio.h>
#include<string.h>
int main(){char s[10001];scanf("%s",s);int n=strlen(s),i=0;while(i<n){int cnt=1;while(i+cnt<n&&s[i+cnt]==s[i])cnt++;printf("%c",s[i]);if(cnt>1)printf("%d",cnt);i+=cnt;}printf("\n");}
