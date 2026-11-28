#include<stdio.h>
int main(){char s[1001],t[1001];scanf("%s %s",s,t);int ms[256]={0},mt[256]={0};if(strlen(s)!=strlen(t)){printf("No\n");return 0;}for(int i=0;s[i];i++){if(!ms[(unsigned char)s[i]])ms[(unsigned char)s[i]]=t[i];if(!mt[(unsigned char)t[i]])mt[(unsigned char)t[i]]=s[i];if(ms[(unsigned char)s[i]]!=t[i]||mt[(unsigned char)t[i]]!=s[i]){printf("No\n");return 0;}}printf("Yes\n");}
