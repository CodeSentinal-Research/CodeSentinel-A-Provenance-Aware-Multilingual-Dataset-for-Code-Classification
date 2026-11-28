#include<stdio.h>
#include<ctype.h>
int main(){char s[1001];scanf("%s",s);for(int i=0;s[i];i++)printf("%c",tolower((unsigned char)s[i]));printf("\n");}
