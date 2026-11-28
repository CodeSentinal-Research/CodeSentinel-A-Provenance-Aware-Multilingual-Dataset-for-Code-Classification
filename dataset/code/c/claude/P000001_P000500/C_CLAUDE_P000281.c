#include<stdio.h>
#include<string.h>
int main(){char s[100001],t[100001];scanf("%s %s",s,t);int ns=strlen(s),nt=strlen(t);int need[256]={0},win[256]={0};for(int i=0;t[i];i++)need[(unsigned char)t[i]]++;int miss=nt,l=0,bs=-1,bl=0;for(int r=0;r<ns;r++){int c=(unsigned char)s[r];win[c]++;if(need[c]>0&&win[c]<=need[c])miss--;while(miss==0){if(bs<0||r-l+1<bs){bs=r-l+1;bl=l;}int lc=(unsigned char)s[l];win[lc]--;if(need[lc]>0&&win[lc]<need[lc])miss++;l++;}}if(bs<0)printf("\n");else{char buf[bs+1];strncpy(buf,s+bl,bs);buf[bs]=0;printf("%s\n",buf);}}
