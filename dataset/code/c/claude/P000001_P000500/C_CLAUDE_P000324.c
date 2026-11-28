#include<stdio.h>
#include<string.h>
int main(){char s[1001];scanf("%s",s);int n=strlen(s);char t[2002];strcpy(t,s);strcat(t,s);t[2*n]=0;char mid[2001];strncpy(mid,t+1,2*n-2);mid[2*n-2]=0;printf("%s\n",strstr(mid,s)?"Yes":"No");}
