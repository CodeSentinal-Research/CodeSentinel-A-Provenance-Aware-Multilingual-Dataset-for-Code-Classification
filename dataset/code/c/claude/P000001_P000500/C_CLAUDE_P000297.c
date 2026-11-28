#include<stdio.h>
#include<string.h>
int val(char c){switch(c){case'I':return 1;case'V':return 5;case'X':return 10;case'L':return 50;case'C':return 100;case'D':return 500;case'M':return 1000;}return 0;}
int main(){char s[100];scanf("%s",s);int n=strlen(s),res=0;for(int i=0;i<n;i++){int v=val(s[i]);if(i+1<n&&v<val(s[i+1]))res-=v;else res+=v;}printf("%d\n",res);}
