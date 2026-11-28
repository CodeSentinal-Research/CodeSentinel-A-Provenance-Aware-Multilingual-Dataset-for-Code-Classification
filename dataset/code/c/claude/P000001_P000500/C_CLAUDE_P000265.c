#include<stdio.h>
int main(){char s[1001];scanf("%s",s);int f[256]={0};for(int i=0;s[i];i++)if(!f[(unsigned char)s[i]]){printf("%c",s[i]);f[(unsigned char)s[i]]=1;}printf("\n");}
