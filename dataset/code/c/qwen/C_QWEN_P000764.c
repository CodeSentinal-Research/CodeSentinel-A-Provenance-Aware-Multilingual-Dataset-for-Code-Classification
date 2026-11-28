#include <stdio.h>
#include <string.h>
int main() { char s[101]; long long k; scanf("%s%lld",s,&k); long long len=0; for(int i=0;s[i];i++) { if(s[i]>='a' && s[i]<='z') len++; else len*=s[i]-'0'; } for(int i=strlen(s)-1;i>=0;i--) { k%=len; if(s[i]>='a' && s[i]<='z') { if(k==0 || k==len) { printf("%c\n",s[i]); return 0; } len--; } else len/=s[i]-'0'; } return 0; }
