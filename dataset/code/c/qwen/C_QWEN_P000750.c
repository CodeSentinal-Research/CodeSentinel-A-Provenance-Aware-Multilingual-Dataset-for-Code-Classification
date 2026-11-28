#include <stdio.h>
void gen(int curr, int n) { if(curr>n) return; if(curr>0) printf("%d ",curr); for(int i=(curr==0?1:0);i<=9;i++) gen(curr*10+i,n); }
int main() { int n; scanf("%d",&n); gen(0,n); printf("\n"); return 0; }
