#include<stdio.h>
#include<ctype.h>
int main(){char s[10001];fgets(s,sizeof(s),stdin);int cnt=0,in=0;for(int i=0;s[i];i++){if(!isspace((unsigned char)s[i])){if(!in){cnt++;in=1;}}else in=0;}printf("%d\n",cnt);}
