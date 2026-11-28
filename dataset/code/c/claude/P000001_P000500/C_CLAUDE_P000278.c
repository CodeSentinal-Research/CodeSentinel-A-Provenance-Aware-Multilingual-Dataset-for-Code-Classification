#include<stdio.h>
#include<string.h>
int main(){char s[10001];scanf("%s",s);int n=strlen(s),bs=0,bl=0;for(int i=0;i<n;i++){for(int odd=0;odd<=1;odd++){int l=i,r=i+odd;while(l>=0&&r<n&&s[l]==s[r]){l--;r++;}l++;if(r-l>bs){bs=r-l;bl=l;}}}s[bl+bs]=0;printf("%s\n",s+bl);}
