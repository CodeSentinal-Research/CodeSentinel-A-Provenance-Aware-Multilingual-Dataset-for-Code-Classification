#include <stdio.h>
int findMin(int *a, int n, int i) { if(i==n-1) return a[i]; int m=findMin(a,n,i+1); return a[i]<m?a[i]:m; }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); printf("%d\n",findMin(a,n,0)); return 0; }
