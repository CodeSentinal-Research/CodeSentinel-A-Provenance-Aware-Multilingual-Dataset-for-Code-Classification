#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){char s[101];scanf("%s",s);char*v="aeiouAEIOU";int n=strlen(s),a=0,b=0;for(int i=0;i<n/2;i++)if(strchr(v,s[i]))a++;for(int i=n/2;i<n;i++)if(strchr(v,s[i]))b++;printf("%s\n",a==b?"Yes":"No");}
