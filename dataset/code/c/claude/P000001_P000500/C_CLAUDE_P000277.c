#include<stdio.h>
#include<string.h>
int main(){char s[10001];scanf("%s",s);int pos[256];memset(pos,-1,sizeof(pos));int l=0,best=0;for(int r=0;s[r];r++){if(pos[(unsigned char)s[r]]>=l)l=pos[(unsigned char)s[r]]+1;pos[(unsigned char)s[r]]=r;if(r-l+1>best)best=r-l+1;}printf("%d\n",best);}
