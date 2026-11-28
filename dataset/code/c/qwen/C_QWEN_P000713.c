#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a-*(int*)b; }
void gen(int *a, int n, int t, int i, int *curr, int ci, int sum) { if(sum==t) { for(int j=0;j<ci;j++) printf("%d ",curr[j]); printf("\n"); return; } if(sum>t || i==n) return; curr[ci]=a[i]; gen(a,n,t,i+1,curr,ci+1,sum+a[i]); while(i+1<n && a[i]==a[i+1]) i++; gen(a,n,t,i+1,curr,ci,sum); }
int main() { int n,t; scanf("%d%d",&n,&t); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); qsort(a,n,sizeof(int),cmp); int curr[n]; gen(a,n,t,0,curr,0,0); return 0; }
