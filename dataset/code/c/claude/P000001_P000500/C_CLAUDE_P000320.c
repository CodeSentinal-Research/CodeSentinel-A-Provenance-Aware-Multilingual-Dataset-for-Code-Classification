#include<stdio.h>
#include<string.h>
int main(){char s[10001],c[2];scanf("%s %s",s,c);int n=strlen(s),res[n];int prev=-n;for(int i=0;i<n;i++){if(s[i]==c[0])prev=i;res[i]=i-prev;}prev=2*n;for(int i=n-1;i>=0;i--){if(s[i]==c[0])prev=i;if(prev-i<res[i])res[i]=prev-i;}for(int i=0;i<n;i++)printf("%d%c",res[i],i<n-1?' ':'\n');}
