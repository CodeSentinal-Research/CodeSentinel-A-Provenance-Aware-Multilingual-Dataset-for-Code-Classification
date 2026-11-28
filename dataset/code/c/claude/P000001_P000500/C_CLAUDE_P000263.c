#include<stdio.h>
int main(){char s[1001];scanf("%s",s);int f[256]={0};for(int i=0;s[i];i++)f[(unsigned char)s[i]]++;char res=-1;for(int i=0;s[i];i++)if(f[(unsigned char)s[i]]==1)res=s[i];if(res==-1)printf("-1\n");else printf("%c\n",res);}
