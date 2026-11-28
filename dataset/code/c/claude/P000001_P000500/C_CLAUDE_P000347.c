#include <stdio.h>
#include <string.h>
int main(){char s[1001];scanf("%s",s);int n=strlen(s);for(int i=0,j=n-1;i<j;i++,j--){char t=s[i];s[i]=s[j];s[j]=t;}printf("%s\n",s);return 0;}
