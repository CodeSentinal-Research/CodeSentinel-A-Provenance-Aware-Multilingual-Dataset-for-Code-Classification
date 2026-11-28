#include<stdio.h>
#include<string.h>
int main(){char s[1001];scanf("%s",s);int n=strlen(s),best=0;for(int i=1;i<n;i++){int sc=0;for(int j=0;j<i;j++)if(s[j]=='0')sc++;for(int j=i;j<n;j++)if(s[j]=='1')sc++;if(sc>best)best=sc;}printf("%d\n",best);}
