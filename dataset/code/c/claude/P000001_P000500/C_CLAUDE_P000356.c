#include<stdio.h>
#include<string.h>
int main(){char s[10001],c[2];scanf("%s\n",s);scanf("%c",c);char*p=strchr(s,c[0]);printf("%d\n",p?(int)(p-s):-1);}
