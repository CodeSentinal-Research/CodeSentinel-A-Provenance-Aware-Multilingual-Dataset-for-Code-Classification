#include<stdio.h>
#include<string.h>
int main(){char s[100001];int k;scanf("%s %d",s,&k);int win[26]={},l=0,best=0,mxf=0,n=strlen(s);for(int r=0;r<n;r++){win[s[r]-'A']++;if(win[s[r]-'A']>mxf)mxf=win[s[r]-'A'];if(r-l+1-mxf>k)win[s[l++]-'A']--;best=r-l+1>best?r-l+1:best;}printf("%d\n",best);}
