#include <stdio.h>
void gen(char *chars, int n, int k, char *curr, int ci) { if(ci==k) { curr[ci]='\0'; printf("%s\n",curr); return; } for(int i=0;i<n;i++) { curr[ci]=chars[i]; gen(chars,n,k,curr,ci+1); } }
int main() { int n,k; scanf("%d",&n); char chars[n+1]; for(int i=0;i<n;i++) scanf(" %c",&chars[i]); chars[n]='\0'; scanf("%d",&k); char curr[k+1]; gen(chars,n,k,curr,0); return 0; }
