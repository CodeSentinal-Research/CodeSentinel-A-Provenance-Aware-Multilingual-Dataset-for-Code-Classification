#include <stdio.h>
int max(int *a, int i, int n) { if(i==n-1) return a[i]; int m=max(a, i+1, n); return a[i]>m?a[i]:m; }
int main() { int n; scanf("%d", &n); int a[n]; for(int i=0;i<n;i++) scanf("%d", &a[i]); printf("%d\n", max(a, 0, n)); return 0; }
