#include <stdio.h>
int main(){char s[1001];scanf("%s",s);int f[256]={0};for(int i=0;s[i];i++)f[(unsigned char)s[i]]++;for(int i=0;i<256;i++)if(f[i])printf("%c: %d\n",(char)i,f[i]);return 0;}
