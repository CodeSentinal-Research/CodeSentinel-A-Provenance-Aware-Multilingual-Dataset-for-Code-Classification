#include<stdio.h>
#include<string.h>
int main(){char s1[1001],s2[1001];scanf("%s %s",s1,s2);char d[2002];strcpy(d,s1);strcat(d,s1);printf("%s\n",(strlen(s1)==strlen(s2)&&strstr(d,s2))?"Yes":"No");}
