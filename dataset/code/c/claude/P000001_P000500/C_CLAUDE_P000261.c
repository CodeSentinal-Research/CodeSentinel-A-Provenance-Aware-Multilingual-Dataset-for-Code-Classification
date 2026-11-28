#include<stdio.h>
#include<ctype.h>
int main(){char s[1001];scanf("%s",s);for(int i=0;s[i];i++){if(isupper(s[i]))s[i]=tolower(s[i]);else if(islower(s[i]))s[i]=toupper(s[i]);}printf("%s\n",s);}
