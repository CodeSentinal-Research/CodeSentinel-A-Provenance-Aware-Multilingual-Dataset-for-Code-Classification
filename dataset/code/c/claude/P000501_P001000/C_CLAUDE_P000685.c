#include <stdio.h>
#include <string.h>
int main(){char s[1001];scanf("%s",s);int n=strlen(s),l=0,r=n-1,ok=1;while(l<r){if(s[l]!=s[r]){ok=0;break;}l++;r--;}printf("%s\n",ok?"Yes":"No");return 0;}
