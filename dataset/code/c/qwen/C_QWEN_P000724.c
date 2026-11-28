#include <stdio.h>
#include <string.h>
int maxLen=0;
void gen(char **w, int n, int i, int mask) { if(i==n) { int len=0; for(int j=0;j<26;j++) if(mask&(1<<j)) len++; if(len>maxLen) maxLen=len; return; } int m=0, ok=1; for(int j=0;w[i][j];j++) { int b=1<<(w[i][j]-'a'); if(m&b) { ok=0; break; } m|=b; } if(ok && (mask&m)==0) gen(w,n,i+1,mask|m); gen(w,n,i+1,mask); }
int main() { int n; scanf("%d",&n); char *w[n]; for(int i=0;i<n;i++) { w[i]=malloc(27); scanf("%s",w[i]); } gen(w,n,0,0); printf("%d\n",maxLen); return 0; }
