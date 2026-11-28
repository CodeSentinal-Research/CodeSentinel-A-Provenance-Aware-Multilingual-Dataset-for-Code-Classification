#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){char s[1001];scanf("%s",s);int i=0,j=strlen(s)-1;while(i<j){while(i<j&&!isalpha((unsigned char)s[i]))i++;while(i<j&&!isalpha((unsigned char)s[j]))j--;if(i<j){char t=s[i];s[i]=s[j];s[j]=t;i++;j--;}}printf("%s\n",s);}
