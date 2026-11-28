#include<stdio.h>
int main(){char s1[101],s2[101];scanf("%s %s",s1,s2);int f1[256]={},f2[256]={};for(int i=0;s1[i];i++)f1[(unsigned char)s1[i]]=1;for(int i=0;s2[i];i++)f2[(unsigned char)s2[i]]=1;for(int i=0;i<256;i++)if(f1[i]!=f2[i]){printf("No\n");return 0;}printf("Yes\n");}
