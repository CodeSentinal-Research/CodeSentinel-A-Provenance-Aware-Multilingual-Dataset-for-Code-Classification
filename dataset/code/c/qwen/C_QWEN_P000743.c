#include <stdio.h>
void sort(int *a, int n) { if(n<=1) return; for(int i=0;i<n-1;i++) if(a[i]>a[i+1]) { int t=a[i]; a[i]=a[i+1]; a[i+1]=t; } sort(a,n-1); }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); sort(a,n); for(int i=0;i<n;i++) printf("%d ",a[i]); printf("\n"); return 0; }
