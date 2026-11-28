#include<stdio.h>
#include<ctype.h>
int main(){char s[10001];fgets(s,sizeof(s),stdin);int cap=1;for(int i=0;s[i];i++){if(s[i]==" "){cap=1;printf(" ");}else{if(cap){printf("%c",toupper((unsigned char)s[i]));cap=0;}else printf("%c",tolower((unsigned char)s[i]));}}printf("\n");}
