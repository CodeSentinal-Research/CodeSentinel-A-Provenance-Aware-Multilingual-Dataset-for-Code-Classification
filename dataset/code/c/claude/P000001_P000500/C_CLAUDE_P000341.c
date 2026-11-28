#include<stdio.h>
#include<string.h>
long long val(char*s){long long v=0;for(int i=0;s[i];i++)v=v*10+(s[i]-'a');return v;}
int main(){char a[101],b[101],t[101];scanf("%s %s %s",a,b,t);printf("%s\n",val(a)+val(b)==val(t)?"Yes":"No");}
