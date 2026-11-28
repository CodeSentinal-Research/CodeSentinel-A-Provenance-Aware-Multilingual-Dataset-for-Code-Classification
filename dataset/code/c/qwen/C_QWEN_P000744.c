#include <stdio.h>
void sort(int *a, int i, int n) { if(i==n) return; int min=i; for(int j=i+1;j<n;j++) if(a[j]<a[min]) min=j; int t=a[i]; a[i]=a[min]; a[min]=t; sort(a,i+1,n); }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); sort(a,0,n); for(int i=0;i<n;i++) printf("%d ",a[i]); printf("\n"); return 0; }
