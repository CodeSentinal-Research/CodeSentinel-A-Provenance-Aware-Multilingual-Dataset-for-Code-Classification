#include<stdio.h>
#include<string.h>
int main(){char s[1001];scanf("%s",s);char*vow="aeiouAEIOU";int n=strlen(s),i=0,j=n-1;while(i<j){while(i<j&&!strchr(vow,s[i]))i++;while(i<j&&!strchr(vow,s[j]))j--;if(i<j){char t=s[i];s[i]=s[j];s[j]=t;i++;j--;}}printf("%s\n",s);}
