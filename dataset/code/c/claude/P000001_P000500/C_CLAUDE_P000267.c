#include<stdio.h>
int main(){char s[1001],o[2],n[2];scanf("%s %s %s",s,o,n);for(int i=0;s[i];i++)printf("%c",s[i]==o[0]?n[0]:s[i]);printf("\n");}
