#include<stdio.h>
#include<string.h>
int main(){char s[10001];scanf("%s",s);int a=0,ok=1;for(int i=0;s[i];i++){if(s[i]=='A')a++;if(a>1){ok=0;break;}if(i>=2&&s[i]=='L'&&s[i-1]=='L'&&s[i-2]=='L'){ok=0;break;}}printf("%s\n",ok?"Yes":"No");}
