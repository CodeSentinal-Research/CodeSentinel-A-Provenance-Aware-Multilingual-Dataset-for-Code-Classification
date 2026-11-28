#include <stdio.h>
void gen(int n, char *curr, int ci, int last) { if(ci==n) { curr[ci]='\0'; printf("%s\n",curr); return; } curr[ci]='0'; gen(n,curr,ci+1,0); if(last==0) { curr[ci]='1'; gen(n,curr,ci+1,1); } }
int main() { int n; scanf("%d",&n); char curr[n+1]; gen(n,curr,0,0); return 0; }
