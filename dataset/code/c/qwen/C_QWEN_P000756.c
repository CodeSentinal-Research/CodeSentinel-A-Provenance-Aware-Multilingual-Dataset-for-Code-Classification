#include <stdio.h>
int partition(int *a, int l, int r) { int p=a[r], i=l-1; for(int j=l;j<r;j++) if(a[j]<=p) { i++; int t=a[i]; a[i]=a[j]; a[j]=t; } int t=a[i+1]; a[i+1]=a[r]; a[r]=t; return i+1; }
void sort(int *a, int l, int r) { if(l<r) { int p=partition(a,l,r); sort(a,l,p-1); sort(a,p+1,r); } }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); sort(a,0,n-1); for(int i=0;i<n;i++) printf("%d ",a[i]); printf("\n"); return 0; }
