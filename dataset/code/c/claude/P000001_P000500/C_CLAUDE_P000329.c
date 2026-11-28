#include<stdio.h>
int main(){char s[101],t[102];scanf("%s %s",s,t);int diff=0;for(int i=0;s[i];i++)diff^=s[i];for(int i=0;t[i];i++)diff^=t[i];printf("%c\n",diff);}
