#include<stdio.h>
int main(){char s[100001];scanf("%s",s);int opens=0,closes=0;
for(int i=0;s[i];i++){if(s[i]=='(')opens++;else{if(opens>0)opens--;else closes++;}}
printf("%d\n",opens+closes);}
