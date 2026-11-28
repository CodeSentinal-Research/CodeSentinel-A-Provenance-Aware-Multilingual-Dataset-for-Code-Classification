#include <stdio.h>
void swap(int *a, int *b) { int t=*a; *a=*b; *b=t; }
void gen(int *a, int l, int r) { if(l==r) { for(int i=0;i<=r;i++) printf("%d ",a[i]); printf("\n"); return; } for(int i=l;i<=r;i++) { swap(&a[l],&a[i]); gen(a,l+1,r); swap(&a[l],&a[i]); } }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); gen(a,0,n-1); return 0; }
