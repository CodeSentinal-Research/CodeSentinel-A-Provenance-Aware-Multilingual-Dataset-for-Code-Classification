#include<stdio.h>
int main(){char s[10];scanf("%s",s);int res=0;for(int i=0;s[i];i++)res=res*26+(s[i]-'A'+1);printf("%d\n",res);}
