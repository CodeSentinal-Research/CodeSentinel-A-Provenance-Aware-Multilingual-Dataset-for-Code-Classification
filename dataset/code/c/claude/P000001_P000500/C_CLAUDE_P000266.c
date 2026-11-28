#include<stdio.h>
int main(){char s[1001],c[2];scanf("%s %s",s,c);for(int i=0;s[i];i++)if(s[i]!=c[0])printf("%c",s[i]);printf("\n");}
