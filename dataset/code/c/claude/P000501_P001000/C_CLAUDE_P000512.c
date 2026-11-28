#include<stdio.h>
int main(){char s[100001];scanf("%s",s);int cnt=0,opens=0;
for(int i=0;s[i];i++){if(s[i]=='[')opens++;else{if(opens>0)opens--;else cnt++;}}
printf("%d\n",(cnt+1)/2);}
