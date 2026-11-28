#include <stdio.h>
#include <stdlib.h>
int sums[1<<20], idx=0;
void gen(int *a, int n, int i, int sum) { if(i==n) { sums[idx++]=sum; return; } gen(a,n,i+1,sum+a[i]); gen(a,n,i+1,sum); }
int cmp(const void *a, const void *b) { return *(int*)a-*(int*)b; }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); gen(a,n,0,0); qsort(sums,idx,sizeof(int),cmp); for(int i=0;i<idx;i++) printf("%d ",sums[i]); printf("\n"); return 0; }
