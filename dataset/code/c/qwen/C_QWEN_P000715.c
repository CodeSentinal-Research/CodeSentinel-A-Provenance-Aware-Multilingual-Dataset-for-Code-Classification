#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a-*(int*)b; }
void gen(int *a, int n, int i, int *curr, int ci) { if(i==n) { for(int j=0;j<ci;j++) printf("%d ",curr[j]); printf("\n"); return; } curr[ci]=a[i]; gen(a,n,i+1,curr,ci+1); while(i+1<n && a[i]==a[i+1]) i++; gen(a,n,i+1,curr,ci); }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); qsort(a,n,sizeof(int),cmp); int curr[n]; gen(a,n,0,curr,0); return 0; }
