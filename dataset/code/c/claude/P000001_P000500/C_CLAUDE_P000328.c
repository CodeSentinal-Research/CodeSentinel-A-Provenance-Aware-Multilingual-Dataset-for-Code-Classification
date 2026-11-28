#include<stdio.h>
int main(){char s[10001];scanf("%s",s);int f[256]={0};for(int i=0;s[i];i++)f[(unsigned char)s[i]]++;for(int i=0;s[i];i++)if(f[(unsigned char)s[i]]==1){printf("%d\n",i);return 0;}printf("-1\n");}
