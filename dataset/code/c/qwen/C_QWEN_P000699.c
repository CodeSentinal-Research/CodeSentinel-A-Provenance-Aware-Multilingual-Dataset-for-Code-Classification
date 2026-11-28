#include <stdio.h>
void rev(int *a, int l, int r) { if(l>=r) return; int t=a[l]; a[l]=a[r]; a[r]=t; rev(a, l+1, r-1); }
int main() { int n; scanf("%d", &n); int a[n]; for(int i=0;i<n;i++) scanf("%d", &a[i]); rev(a, 0, n-1); for(int i=0;i<n;i++) printf("%d ", a[i]); printf("\n"); return 0; }
