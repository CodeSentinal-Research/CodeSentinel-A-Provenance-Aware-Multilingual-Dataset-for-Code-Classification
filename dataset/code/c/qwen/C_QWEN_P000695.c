#include <stdio.h>
int bs(int *a, int l, int r, int t) { if(l>r) return -1; int m=l+(r-l)/2; if(a[m]==t) { int res=bs(a, l, m-1, t); return res==-1?m:res; } if(a[m]<t) return bs(a, m+1, r, t); return bs(a, l, m-1, t); }
int main() { int n, t; scanf("%d %d", &n, &t); int a[n]; for(int i=0;i<n;i++) scanf("%d", &a[i]); printf("%d\n", bs(a, 0, n-1, t)); return 0; }
