#include <stdio.h>
void gen(int n, int o, int c, char *curr, int ci) { if(ci==2*n) { curr[ci]='\0'; printf("%s\n",curr); return; } if(o<n) { curr[ci]='('; gen(n,o+1,c,curr,ci+1); } if(c<o) { curr[ci]=')'; gen(n,o,c+1,curr,ci+1); } }
int main() { int n; scanf("%d",&n); char curr[2*n+1]; gen(n,0,0,curr,0); return 0; }
