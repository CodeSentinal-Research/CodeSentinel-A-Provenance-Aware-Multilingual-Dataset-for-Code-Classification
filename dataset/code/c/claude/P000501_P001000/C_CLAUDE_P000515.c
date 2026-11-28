#include<stdio.h>
int main(){char s[100001];fgets(s,sizeof(s),stdin);int d=0,mx=0;
for(int i=0;s[i];i++){if(s[i]=='('){d++;if(d>mx)mx=d;}else if(s[i]==')')d--;}
printf("%d\n",mx);}
