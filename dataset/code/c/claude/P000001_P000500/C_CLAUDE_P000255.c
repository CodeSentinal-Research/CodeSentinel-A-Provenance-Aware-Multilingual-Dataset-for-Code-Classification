#include<stdio.h>
#include<string.h>
int main(){char s[1001];scanf("%s",s);char*v="aeiouAEIOU";for(int i=0;s[i];i++)if(!strchr(v,s[i]))printf("%c",s[i]);printf("\n");}
