#include<stdio.h>
#include<limits.h>
#include<ctype.h>
int main(){char s[101];scanf("%s",s);int i=0,sign=1;long long res=0;while(s[i]==" ")i++;if(s[i]=="+"||s[i]=="-"){if(s[i]=="-")sign=-1;i++;}while(isdigit(s[i])){res=res*10+(s[i++]-"0");if(res*sign>INT_MAX){printf("%d\n",INT_MAX);return 0;}if(res*sign<INT_MIN){printf("%d\n",INT_MIN);return 0;}}printf("%d\n",(int)(res*sign));}
