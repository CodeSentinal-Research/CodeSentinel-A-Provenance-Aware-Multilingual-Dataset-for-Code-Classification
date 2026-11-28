#include<stdio.h>
int main(){char s1[1001],s2[1001];scanf("%s %s",s1,s2);int f[256]={0};for(int i=0;s1[i];i++)f[(unsigned char)s1[i]]++;for(int i=0;s2[i];i++)f[(unsigned char)s2[i]]--;for(int i=0;i<256;i++)if(f[i]){printf("No\n");return 0;}printf("Yes\n");}
