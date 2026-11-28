#include<stdio.h>
int main(){char s[101];scanf("%s",s);for(int i=0;s[i];i+=2){printf("%c",s[i]);if(s[i+1])printf("%c",s[i]+(s[i+1]-'0'));}printf("\n");}
