#include<stdio.h>
#include<string.h>
int isPalin(char*s,int l,int r){while(l<r)if(s[l++]!=s[r--])return 0;return 1;}
int check(char*a,char*b,int n){int i=0,j=n-1;while(i<j&&a[i]==b[j]){i++;j--;}return isPalin(a,i,j)||isPalin(b,i,j);}
int main(){char a[1001],b[1001];scanf("%s %s",a,b);int n=strlen(a);printf("%s\n",(check(a,b,n)||check(b,a,n))?"Yes":"No");}
